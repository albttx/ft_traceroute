/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:59 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 13:49:11 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

# define MAXHOSTNAMELEN 64

int		print_err(int type, int code)
{
	if (type != ICMP_TIMXCEED || type != ICMP_UNREACH)
		return (1);
	switch (code)
	{
		case ICMP_UNREACH_PORT:
			return (42);
		case ICMP_UNREACH_NET:
			printf(" !N");
			break ;
		case ICMP_UNREACH_HOST:
			printf(" !H");
			break ;
		case ICMP_UNREACH_PROTOCOL:
			printf(" !P");
			return (42);
		case ICMP_UNREACH_NEEDFRAG:
			printf(" !F");
			break ;
		case ICMP_UNREACH_SRCFAIL:
			printf(" !S");
			break ;
	}
	return (1);
}

void	print_dns(struct in_addr in)
{
	int					err;
	char				*c;
	char				domain[MAXHOSTNAMELEN + 1];
	struct hostent		*hp;

	c = NULL;
	ft_bzero(domain, sizeof(domain));
	hp = gethostbyaddr((char *)&in, sizeof(in), AF_INET);
	if (hp)
	{
		ft_strcpy(domain, hp->h_name);
		printf("(%s)", domain);
	}
}

void	print_probe(t_probe *probe)
{
	t_opacket		*op;
	struct ip		*ip;

	op = (t_opacket *)probe->packet;
	ip = &op->ip;
	printf("%s", GREEN);
	printf("%-16s ", probe->hostip);
	print_dns((probe->from).sin_addr);
	printf("%s", DEFAULT);
}
