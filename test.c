
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h> 

// The packet length
#define PCKT_LEN 8192 

// Source IP, source port, target IP, target port from the command line arguments
int main(int argc, char *argv[])
{
    int send, recv, resp;
    int ttl = 1; // Time to live
    char buffer[PCKT_LEN];

    // Destination address
    struct sockaddr_in dst;

    // ICMP Response
    struct msghdr icmp;

    memset(buffer, 0, PCKT_LEN);

    // Create a raw socket with UDP protocol
    if ((send = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        perror("Could not process socket() [send].");
        return EXIT_FAILURE;
    }

    // ICMP Socket
    if ((recv = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("Could not process socket() [recv].");
        return EXIT_FAILURE;
    }

    dst.sin_family      = AF_INET;
    dst.sin_addr.s_addr = inet_addr("74.125.39.106");
    dst.sin_port        = htons(60001);

    // Define time to life
    if(setsockopt(send, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0)
    {
        perror("Could not process setsockopt().");
        return EXIT_FAILURE;
    }

    if(sendto(send, buffer, sizeof(buffer), 0, (struct sockaddr *) &dst, sizeof(dst)) < 0)
    {
        perror("Could not process sendto().");
        return EXIT_FAILURE;
    }


    /*if((resp = recvmsg(recv, (struct msghdr *) &icmp, IP_RECVERR|MSG_ERRQUEUE)) < 0 )*/
    /*{*/
        /*perror("Could not process recvmsg().");*/
        /*return EXIT_FAILURE;*/
    /*}*/

	char buf[100];
	bzero(buf, sizeof(buf));

	struct sockaddr_in rcv;
	bzero(&rcv, sizeof(rcv));

	socklen_t size;
	bzero(&size, sizeof(size));

	int cc = recvfrom(recv, buf, 100, 0, (struct sockaddr *)&rcv,&size);
	printf("cc = %d\n", cc);
	inet_ntoa(rcv.sin_addr);
	/*printf("from %s \n", inet_ntoa(rcv.sin_addr));*/
	/*printf("Received packet from %s:%d\nData: %s\n\n", inet_ntoa(rcv.sin_addr), ntohs(rcv.sin_port), buf);*/

    close(send);
    close(recv);

    return 0;
}
