/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:59 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/09 14:53:15 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"
#include <netdb.h>

void	print_dns(char *ipaddr, struct sockaddr_in *sa)
{
	int					err;
	char				host[NI_MAXHOST];

	ft_bzero(&sa, sizeof(sa));
	ft_bzero(host, sizeof(host));
	err = getnameinfo((struct sockaddr *)sa, sizeof(*sa), host, sizeof(host), NULL, 0, 0);
	if (err)
		perror("getnameinfo");
	printf("%d (%s)", err, host);
}

void	print_probe(int cc, char *packet, struct sockaddr_in *from)
{
	t_opacket		*op;
	struct ip		*ip;
	char			*ipaddr;

	op = (t_opacket *)packet;
	ip = &op->ip;
	ipaddr = inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr);
	printf(" %s ", ipaddr);
	/*print_dns(ipaddr, from);*/
	printf(" %d bytes ", cc);
	/*printf("to %s ", inet_ntoa(*(struct in_addr *)&ip->ip_dst.s_addr));*/
	/*printf("ttl (%d or %d) ", ip->ip_ttl, op->ttl);*/
	/*printf("\n");*/
}
