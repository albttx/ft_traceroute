/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:59 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/09 19:39:52 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"
#include <netdb.h>
# define MAXHOSTNAMELEN 64

void	print_dns(struct in_addr in)
{
	int					err;
	char				*c;
	char				domain[MAXHOSTNAMELEN + 1];
	struct hostent		*hp;

	c = NULL;
	ft_bzero(domain, sizeof(domain));
	// gethostname()
	hp = gethostbyaddr((char *)&in, sizeof(in), AF_INET);
	if (hp)
	{
		ft_strcpy(domain, hp->h_name);
		printf("%s", domain);
	}
}

void	print_probe(t_probe *probe)
{
	t_opacket		*op;
	struct ip		*ip;

	op = (t_opacket *)probe->packet;
	ip = &op->ip;
	printf("%s", GREEN);
	printf("\t%-16s ", probe->hostip);
	printf(" %ld bytes ", probe->cc);
	print_dns((probe->from).sin_addr);
	/*printf("to %s ", inet_ntoa(*(struct in_addr *)&ip->ip_dst.s_addr));*/
	/*printf("ttl (%d or %d) ", ip->ip_ttl, op->ttl);*/
	printf("%s", DEFAULT);
	printf("\n");
}
