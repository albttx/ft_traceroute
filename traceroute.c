
#include <sys/param.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/ioctl.h>

#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>

#include <arpa/inet.h>

#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define	MAXPACKET	65535	/* max ip packet size */
#define MAXHOSTNAMELEN	64

#define Fprintf (void)fprintf
#define Sprintf (void)sprintf
#define Printf (void)printf

/*
 * format of a (udp) probe packet.
 */
struct opacket {
	struct ip ip;
	struct udphdr udp;
	unsigned char seq;		/* sequence number of this packet */
	unsigned char ttl;		/* ttl packet left with */
	struct timeval tv;	/* time packet left */
};

unsigned char	packet[512];		/* last inbound (icmp) packet */
/*struct opacket	outpacket;	[> last output (udp) packet <]*/
char 	*hostip;

int wait_for_reply __P((int, struct sockaddr_in *));
void send_probe __P((int, int));
double deltaT __P((struct timeval *, struct timeval *));
int packet_ok __P((unsigned char *, int, struct sockaddr_in *, int));
void print __P((unsigned char *, int, struct sockaddr_in *));
void tvsub __P((struct timeval *, struct timeval *));
char *inetname __P((struct in_addr));
void usage __P(());

int s;				/* receive (icmp) socket file descriptor */
int sndsock;			/* send (udp) socket file descriptor */
struct timezone tz;		/* leftover */

struct sockaddr whereto;	/* Who to try to reach */
int datalen;			/* How much data */

char *source = 0;
char *hostname;

int nprobes = 3;
int max_ttl = 30;
unsigned short ident;
unsigned short port = 32768+666;	/* start udp dest port # for probe packets */
int options;			/* socket options */
int verbose;
int waittime = 2;		/* time to wait for response (in seconds) */
int nflag;			/* print addresses numerically */
struct sockaddr_in	*to;

int
main(argc, argv)
	int argc;
	char *argv[];
{
	extern char *optarg;
	extern int optind;
	struct hostent *hp;
	struct sockaddr_in from;
	int ch, i, on, probe, seq, tos, ttl;

	on = 1;
	seq = tos = 0;
	to = (struct sockaddr_in *)&whereto;
	argc -= optind;
	argv += optind;

	if (argc < 1)
		usage();

	/*setlinebuf (stdout);*/

	(void) bzero((char *)&whereto, sizeof(struct sockaddr));
	to->sin_family = AF_INET;
	to->sin_addr.s_addr = inet_addr(*argv);
	hostip = inet_ntoa(to->sin_addr);
	if (to->sin_addr.s_addr != -1)
		hostname = *argv;
	else {
		hp = gethostbyname(*argv);
		if (hp) {
			to->sin_family = hp->h_addrtype;
			bcopy(hp->h_addr, (caddr_t)&to->sin_addr, hp->h_length);
			hostname = hp->h_name;
		} else {
			(void)fprintf(stderr,
			    "traceroute: unknown host %s\n", *argv);
			exit(1);
		}
	}
	
	datalen += sizeof(struct opacket);
	ident = (getpid() & 0xffff) | 0x8000;

	if ((s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
		perror("traceroute: icmp socket");
		exit(5);
	}
	if ((sndsock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
		perror("traceroute: raw socket");
		exit(5);
	}
	Fprintf(stderr, "traceroute to %s (%s)", hostname, inet_ntoa(to->sin_addr));
	/*inet_ntoa(to->sin_addr);*/
	Fprintf(stderr, ", %d hops max, %d byte packets\n", max_ttl, datalen);
	(void) fflush(stderr);

	for (ttl = 1; ttl <= max_ttl; ++ttl) {
		unsigned long lastaddr = 0;
		int got_there = 0;
		int unreachable = 0;

		Printf("%2d ", ttl);
		/*for (probe = 0; probe < nprobes; ++probe) {*/
		for (probe = 0; probe < 3; ++probe) {
			int cc;
			struct timeval t1, t2;
			struct timezone tz;
			struct ip *ip;

			/*(void) gettimeofday(&t1, &tz);*/
			send_probe(++seq, ttl);
			cc = wait_for_reply(s, &from);
			/*(void) gettimeofday(&t2, &tz);*/
			if ((i = packet_ok(packet, cc, &from, seq))) {
				/*if (from.sin_addr.s_addr != lastaddr) {*/
					/*print(packet, cc, &from);*/
					lastaddr = from.sin_addr.s_addr;
				/*}*/
				/*Printf("  %g ms", deltaT(&t1, &t2));*/
				switch(i - 1) {
				case ICMP_UNREACH_PORT:
					++got_there;
					break;
				case ICMP_UNREACH_NET:
					++unreachable;
					Printf(" !N");
					break;
				case ICMP_UNREACH_HOST:
					++unreachable;
					Printf(" !H");
					break;
				case ICMP_UNREACH_PROTOCOL:
					++got_there;
					Printf(" !P");
					break;
				case ICMP_UNREACH_NEEDFRAG:
					++unreachable;
					Printf(" !F");
					break;
				case ICMP_UNREACH_SRCFAIL:
					++unreachable;
					Printf(" !S");
					break;
				}
				break;
			}
			if (cc == 0)
				Printf(" *");
			(void) fflush(stdout);
		}
		putchar('\n');
		if (got_there || unreachable >= nprobes-1)
			exit(0);
	}
}

int
wait_for_reply(sock, from)
	int sock;
	struct sockaddr_in *from;
{
	fd_set fds;
	struct timeval wait;
	int cc = 0;
	int fromlen = sizeof (*from);

	bzero(from, sizeof(*from));
	bzero(packet, sizeof(packet));
	FD_ZERO(&fds);
	FD_SET(sock, &fds);
	wait.tv_sec = 1;
	wait.tv_usec = 500;

	if (select(sock+1, &fds, (fd_set *)0, (fd_set *)0, &wait) > 0)
	{
		cc = recvfrom(s, (char *)packet, sizeof(packet), 0, (struct sockaddr *)from, &fromlen);
		printf("cc = %d ", cc);
	}
	return(cc);
}


void
send_probe(seq, ttl)
	int seq, ttl;
{
	struct opacket	op;
	struct sockaddr_in	myto;
	int i;

	bzero(&myto, sizeof(myto));
	myto.sin_family = AF_INET;
	myto.sin_addr.s_addr = inet_addr(hostip);
	myto.sin_port = port;

	bzero(&op, sizeof(op));
	(op.ip).ip_off = 0;
	(op.ip).ip_hl = sizeof(op.ip) >> 2;
	(op.ip).ip_p = IPPROTO_UDP;
	(op.ip).ip_len = datalen;
	(op.ip).ip_ttl = ttl;
	(op.ip).ip_v = IPVERSION;
	(op.ip).ip_id = htons(ident+seq);
	(op.ip).ip_tos = 0;
	(op.ip).ip_dst = to->sin_addr;

	(op.udp).uh_sport = htons(ident);
	(op.udp).uh_dport = htons(port+seq);
	(op.udp).uh_ulen = htons((unsigned short)(datalen - sizeof(struct ip)));
	(op.udp).uh_sum = 0;

	op.seq = seq;
	op.ttl = ttl;
	
	i = sendto(sndsock, (char *)&op, sizeof(op), 0, (struct sockaddr *)&myto, sizeof(myto));
	if (i < 0 || i != datalen)  {
		if (i<0)
			perror("sendto");
		Printf("traceroute: wrote %s %d chars, ret=%d\n", hostname, datalen, i);
		(void) fflush(stdout);
	}
}


double
deltaT(t1p, t2p)
	struct timeval *t1p, *t2p;
{
	register double dt;

	dt = (double)(t2p->tv_sec - t1p->tv_sec) * 1000.0 +
	     (double)(t2p->tv_usec - t1p->tv_usec) / 1000.0;
	return (dt);
}


/*
 * Convert an ICMP "type" field to a printable string.
 */
char *
pr_type(t)
	unsigned char t;
{
	static char *ttab[] = {
	"Echo Reply",	"ICMP 1",	"ICMP 2",	"Dest Unreachable",
	"Source Quench", "Redirect",	"ICMP 6",	"ICMP 7",
	"Echo",		"ICMP 9",	"ICMP 10",	"Time Exceeded",
	"Param Problem", "Timestamp",	"Timestamp Reply", "Info Request",
	"Info Reply"
	};

	if(t > 16)
		return("OUT-OF-RANGE");

	return(ttab[t]);
}


int
packet_ok(buf, cc, from, seq)
	unsigned char *buf;
	int cc;
	struct sockaddr_in *from;
	int seq;
{
	register struct icmp *icp;
	unsigned char type, code;
	int hlen;
	struct ip *ip;

	ip = (struct ip *) buf;
	hlen = ip->ip_hl << 2;
	if (cc < hlen + ICMP_MINLEN) {
		/*if (verbose)*/
			Printf("packet too short (%d bytes) from %s\n", cc, inet_ntoa(from->sin_addr));
		return (0);
	}
	print(buf, cc, from);
	cc -= hlen;
	icp = (struct icmp *)(buf + hlen);

	type = icp->icmp_type; code = icp->icmp_code;
	if ((type == ICMP_TIMXCEED && code == ICMP_TIMXCEED_INTRANS) ||
	    type == ICMP_UNREACH) {
		struct ip *hip;
		struct udphdr *up;

		hip = &icp->icmp_ip;
		hlen = hip->ip_hl << 2;
		up = (struct udphdr *)((unsigned char *)hip + hlen);
		if (hlen + 12 <= cc && hip->ip_p == IPPROTO_UDP &&
		    up->uh_sport == htons(ident) &&
		    up->uh_dport == htons(port+seq))
			return (type == ICMP_TIMXCEED? -1 : code+1);
	}
	return(0);
}


void
print(buf, cc, from)
	unsigned char *buf;
	int cc;
	struct sockaddr_in *from;
{
	struct ip *ip;
	int hlen;

	ip = (struct ip *) buf;
	hlen = ip->ip_hl << 2;
	cc -= hlen;

	/*if (nflag)*/
		Printf(" %s", inet_ntoa(from->sin_addr));
	/*else*/
		/*Printf(" %s (%s)", inetname(from->sin_addr), inet_ntoa(from->sin_addr));*/

	/*if (verbose)*/
		/*Printf (" %d bytes to %s", cc, inet_ntoa (ip->ip_dst));*/
}


/*
 * Subtract 2 timeval structs:  out = out - in.
 * Out is assumed to be >= in.
 */
void
tvsub(out, in)
	register struct timeval *out, *in;
{
	if ((out->tv_usec -= in->tv_usec) < 0)   {
		out->tv_sec--;
		out->tv_usec += 1000000;
	}
	out->tv_sec -= in->tv_sec;
}


/*
 * Construct an Internet address representation.
 * If the nflag has been supplied, give
 * numeric value, otherwise try for symbolic name.
 */
char *
inetname(in)
	struct in_addr in;
{
	register char *cp;
	static char line[50];
	struct hostent *hp;
	static char domain[MAXHOSTNAMELEN + 1];
	static int first = 1;

	if (first && !nflag) {
		first = 0;
		if (gethostname(domain, MAXHOSTNAMELEN) == 0 &&
		    (cp = index(domain, '.')))
			(void) strcpy(domain, cp + 1);
		else
			domain[0] = 0;
	}
	cp = 0;
	if (!nflag && in.s_addr != INADDR_ANY) {
		hp = gethostbyaddr((char *)&in, sizeof (in), AF_INET);
		if (hp) {
			if ((cp = index(hp->h_name, '.')) &&
			    !strcmp(cp + 1, domain))
				*cp = 0;
			cp = hp->h_name;
		}
	}
	if (cp)
		(void) strcpy(line, cp);
	else {
		in.s_addr = ntohl(in.s_addr);
#define C(x)	((x) & 0xff)
		Sprintf(line, "%lu.%lu.%lu.%lu", C(in.s_addr >> 24),
			C(in.s_addr >> 16), C(in.s_addr >> 8), C(in.s_addr));
	}
	return (line);
}

void
usage()
{
	(void)fprintf(stderr,
"usage: traceroute [-dnrv] [-m max_ttl] [-p port#] [-q nqueries]\n\t\
[-s src_addr] [-t tos] [-w wait] host [data size]\n");
	exit(1);
}
