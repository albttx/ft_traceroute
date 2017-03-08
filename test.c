
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h> 
#include <netinet/udp.h> 
#include <netinet/ip_icmp.h> 

#define PCKT_LEN 512 
#define PORT (32768 + 666)
/*#define PCKT_LEN 8192 */
#define GOOGLE "216.58.213.163"

static char	*pr_icmp_err_code(struct icmp *icmp)
{
	if (icmp->icmp_type == ICMP_UNREACH)
	{
		if (icmp->icmp_code == ICMP_UNREACH_NET)
			return ("Destination Net Unreachable");
		else if (icmp->icmp_code == ICMP_UNREACH_HOST)
			return ("Destination Host Unreachable");
		else if (icmp->icmp_code == ICMP_UNREACH_PROTOCOL)
			return ("Destination Protocol Unreachable");
		else if (icmp->icmp_code == ICMP_UNREACH_PORT)
			return ("Destination Port Unreachable");
		else if (icmp->icmp_code == ICMP_UNREACH_NEEDFRAG)
			return ("frag needed and DF set");
		else
			return ("Dest Unreachable, Bad Code)");
	}
	else if (icmp->icmp_type == ICMP_TIMXCEED)
	{
		if (icmp->icmp_code == ICMP_TIMXCEED_REASS)
			return ("Frag reassembly time exceeded");
		else
			return ("Time to live exceeded");
	}
	else
		return ("Unknown type.");
}

int		main(int argc, char *argv[]) {
	int					send_sock;
	int					recv_sock;
	int					resp;
	int					ttl = 1;
	char				buffer[PCKT_LEN];
	struct sockaddr_in	dst;
	struct ip			*ip;
	struct udphdr		*udp_h;
	/*struct icmphdr		*icmp_h;*/

	bzero(&buffer, sizeof(buffer));
	bzero(&dst, sizeof(dst));

	if ((send_sock = socket(PF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
		perror("Could not process socket() [send].");
		return EXIT_FAILURE;
	}

	if ((recv_sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
		perror("Could not process socket() [recv].");
		return EXIT_FAILURE;
	}

	dst.sin_family      = AF_INET;
	dst.sin_addr.s_addr = inet_addr(GOOGLE);
	dst.sin_port        = htons(PORT);
	ip = (struct ip *)buffer;
	udp_h = (struct udphdr *)((void *)buffer + sizeof(*ip));
	/*icmp_h = (struct icmphdr *)((void *)buffer + sizeof(*ip));*/

	ip->ip_off = 0;
	ip->ip_hl = sizeof(*ip) >> 2;
	ip->ip_p = IPPROTO_UDP;
	ip->ip_len = sizeof(struct ip) + sizeof(struct udphdr);
	ip->ip_ttl = 1;
	ip->ip_tos = 0;
	ip->ip_v = IPVERSION;
	ip->ip_dst = dst.sin_addr;
	ip->ip_id = 42;

	udp_h->uh_sport = htons(42);
	udp_h->uh_dport = htons(PORT + 0);
	udp_h->uh_ulen = htons((unsigned short)(sizeof(struct udphdr)));
	/*udp_h->uh_ulen = htons((unsigned short)(datalen - sizeof(struct ip)));*/
	udp_h->uh_sum = 0;

	if (sendto(send_sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&dst, sizeof(dst)) < 0) {
		perror("Could not process sendto().");
		return EXIT_FAILURE;
	}

	char				buff[PCKT_LEN];
	struct sockaddr_in	from;
	socklen_t			size;
	int					cc;
	struct icmp			*icmp;

	ip = NULL;
	icmp = NULL;
	bzero(buff, sizeof(buff));
	bzero(&from, sizeof(from));
	bzero(&size, sizeof(size));

	size = sizeof(from);
	printf("wait to receive...\n");
	if ((cc = recvfrom(recv_sock, buff, PCKT_LEN, 0, (struct sockaddr *)&from, &size)) < 0) {
		perror("recvfrom:");
		return EXIT_FAILURE;
	}
	printf("cc = %d\n", cc);

	ip = (struct ip *)buff;
	icmp = (void *)ip + sizeof(*ip);

	printf("icmp err %s \n", pr_icmp_err_code(icmp));
	printf("ip->ip_ttl = %d \n", ip->ip_ttl);
	printf("ip->ip_v   = %d \n", ip->ip_v);


	/*printf("src:[%s] ", inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr));*/
	/*printf("dst:[%s] ", inet_ntoa(*(struct in_addr *)&ip->ip_dst.s_addr));*/
	/*printf("Received packet from %s:%d\nData: %s\n\n", inet_ntoa(from.sin_addr), ntohs(from.sin_port), buff);*/

	close(send);
	close(recv);

	return 0;
}
