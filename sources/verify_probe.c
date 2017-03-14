/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_probe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:41:26 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 13:50:45 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

/*
 * return values:
 *  0: no data recv
 *  1: new probe to print
 *  2: for duplicate probe
 * 42: for packet reach final dest || UNREACH_PORT
*/
int		verify_probe(t_env *env, t_probe *probe)
{
	struct ip 				*ip;
	struct icmp				*icmp;
	unsigned char			type;
	unsigned char			code;
	static unsigned long	lastaddr = 0;

	if (probe->cc <= 0)
		return (0);
	ip = (struct ip *)probe->packet;
	icmp = (void *)ip + sizeof(*ip);
	type = icmp->icmp_type;
	code = icmp->icmp_code;
	
	ft_strncpy(probe->hostip, inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr), INET_ADDRSTRLEN);

	// check != previous
	if (ip->ip_src.s_addr == lastaddr)
		return (2);
	lastaddr = ip->ip_src.s_addr; 

	if (ft_strequ(env->hostip, probe->hostip))
		return (42);

	if ((type == ICMP_TIMXCEED && code == ICMP_TIMXCEED_INTRANS) || type == ICMP_UNREACH)
	{
		return (print_err(type, code));
	}
	return (0);
}
