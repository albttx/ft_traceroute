/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_probe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:41:26 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 15:37:38 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static int		check_id(t_env *env, struct icmp *icmp)
{
	struct ip		*ip;
	struct udphdr	*udp;
	int				hlen;

	ip = &icmp->icmp_ip;
	hlen = ip->ip_hl << 2;
	udp = (struct udphdr *)((unsigned char *)ip + hlen);
	if (ip->ip_p == IPPROTO_UDP
		&& udp->uh_sport == htons(env->id)
		&& udp->uh_dport == htons(env->port + env->seq))
	{
		return (1);
	}
	return (-1);
}

int				verify_probe(t_env *env, t_probe *probe)
{
	struct ip 				*ip;
	struct icmp				*icmp;
	unsigned char			type;
	unsigned char			code;

	if (probe->cc <= 0)
		return (0);
	ip = (struct ip *)probe->packet;
	icmp = (void *)ip + sizeof(*ip);
	type = icmp->icmp_type;
	code = icmp->icmp_code;
	ft_strncpy(probe->hostip, inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr), INET_ADDRSTRLEN);
	/*if (ft_strequ(env->hostip, probe->hostip))*/
		/*return (1);*/
	if (check_id(env, icmp) == -1)
		return (0);
	if ((type == ICMP_TIMXCEED && code == ICMP_TIMXCEED_INTRANS) || type == ICMP_UNREACH)
	{
		return (type == ICMP_TIMXCEED ? -1 : code + 1);
	}
	return (0);
}
