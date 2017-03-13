/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_probe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:41:26 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/13 18:33:46 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	print_err(int type, int code)
{
	if (type != ICMP_TIMXCEED || type != ICMP_UNREACH)
		return ;
	switch(code)
	{
		case ICMP_UNREACH_PORT:
			printf("ICMP_UNREACH_PORT\n");
			break;
		case ICMP_UNREACH_NET:
			/*printf("ICMP_UNREACH_NET\n");*/
			printf(" !N");
			break;
		case ICMP_UNREACH_HOST:
			printf(" !H");
			break;
		case ICMP_UNREACH_PROTOCOL:
			printf(" !P");
			break;
		case ICMP_UNREACH_NEEDFRAG:
			printf(" !F");
			break;
		case ICMP_UNREACH_SRCFAIL:
			printf(" !S");
			break;
		}
		/*break;*/
}

/*
 * return values:
 *  1: new probe to print
 *  2: for duplicate probe
 * 42: for packet reach final dest || UNREACH_PORT
 *  0: else
*/
int		verify_probe(t_env *env, t_probe *probe)
{
	struct ip 		*ip;
	struct icmp		*icmp;
	unsigned char	type;
	unsigned char	code;
	static char		previous_probe[INET_ADDRSTRLEN];

	if (probe->cc <= 0)
		return (0);
	ip = (struct ip *)probe->packet;
	icmp = (void *)ip + sizeof(*ip);
	type = icmp->icmp_type;
	code = icmp->icmp_code;
	print_err(type, code);
	ft_strncpy(probe->hostip, inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr), INET_ADDRSTRLEN);
	/*printf("cc = %ld type= %d, code= %d, -> %s\n", probe->cc, type, code, get_icmp_type(type));*/
	if (ft_strequ(previous_probe, probe->hostip))
		return (2);
	if (ft_strequ(env->hostip, probe->hostip))
		return (42);
	ft_strncpy(previous_probe, inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr), INET_ADDRSTRLEN);
	if ((type == ICMP_TIMXCEED && code == ICMP_TIMXCEED_INTRANS) || type == ICMP_UNREACH)
	{
		return (1);
	}
	else if (code == ICMP_UNREACH_PORT)
		return (42);
	return (0);
}
