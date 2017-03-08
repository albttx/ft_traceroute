
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h> 
#include <netinet/ip_icmp.h> 

#define PCKT_LEN 8192 
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
	int					send;
	int					recv;
	int					resp;
	int					ttl = 1;
	char				buffer[PCKT_LEN];
	struct sockaddr_in	dst;

	bzero(&buffer, sizeof(buffer));
	bzero(&dst, sizeof(dst));

	if ((send = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
		perror("Could not process socket() [send].");
		return EXIT_FAILURE;
	}

	if ((recv = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
		perror("Could not process socket() [recv].");
		return EXIT_FAILURE;
	}

	dst.sin_family      = AF_INET;
	dst.sin_addr.s_addr = inet_addr(GOOGLE);
	dst.sin_port        = htons(32768 + 666);

	if (setsockopt(send, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
		perror("Could not process setsockopt().");
		return EXIT_FAILURE;
	}

	if (sendto(send, buffer, sizeof(buffer), 0, (struct sockaddr *)&dst, sizeof(dst)) < 0) {
		perror("Could not process sendto().");
		return EXIT_FAILURE;
	}

	char				buff[PCKT_LEN];
	struct sockaddr_in	from;
	socklen_t			size;
	int					cc;
	struct ip			*ip;
	struct icmp			*icmp;

	bzero(buff, sizeof(buff));
	bzero(&from, sizeof(from));
	bzero(&size, sizeof(size));

	size = sizeof(from);
	if ((cc = recvfrom(recv, buff, PCKT_LEN, 0, (struct sockaddr *)&from, &size)) < 0) {
		perror("recvfrom:");
		return EXIT_FAILURE;
	}
	printf("cc = %d\n\n", cc);

	ip = (struct ip *)buff;
	icmp = (void *)ip + sizeof(*ip);

	printf("sizeof ip       = %ld\n", sizeof(struct ip));
	printf("sizeof iphdr    = %ld\n", sizeof(struct iphdr));
	printf("sizeof icmp     = %ld\n", sizeof(struct icmp));
	printf("sizeof icmphdr  = %ld\n", sizeof(struct icmphdr));
	printf("\n");
	printf("icmp err    = %s \n", pr_icmp_err_code(icmp));
	printf("icmp->icmp_type  = %d \n", icmp->icmp_type);
	printf("icmp->icmp_code  = %d \n", icmp->icmp_code);

	printf("ip->ip_ttl  = %d \n", ip->ip_ttl);
	printf("ip->ip_v    = %d \n", ip->ip_v);
	printf("ip->ip_hl   = %d \n", ip->ip_hl);
	printf("ip->ip_tos  = %d \n", ip->ip_tos);
	printf("ip->ip_p    = %d \n", ip->ip_p);


	/*printf("src:[%s] ", inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr));*/
	/*printf("dst:[%s] ", inet_ntoa(*(struct in_addr *)&ip->ip_dst.s_addr));*/
	/*printf("Received packet from %s:%d\nData: %s\n\n", inet_ntoa(from.sin_addr), ntohs(from.sin_port), buff);*/

	close(send);
	close(recv);

	return 0;
}
