/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:59 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/06 15:45:07 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	print_probe(int cc, char *packet, struct sockaddr_in *from)
{
	t_opacket		*op;
	struct ip		*ip;

	op = (t_opacket *)packet;
	ip = &op->ip;
	printf(" %d ", op->seq);
	printf(" %d bytes from %s to %s -- ", cc, inet_ntoa(from->sin_addr), inet_ntoa(ip->ip_dst));

	printf("src:[%s] ", inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr));
	printf("dst:[%s] ", inet_ntoa(*(struct in_addr *)&ip->ip_dst.s_addr));
	printf("ttl (%d or %d) ", ip->ip_ttl, op->ttl);
	printf("\n");
}
