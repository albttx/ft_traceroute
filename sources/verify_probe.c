/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_probe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:41:26 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/09 18:56:53 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

#define DUPLICATE 2
#define DONE_PACK 42

static char		*get_icmp_type(unsigned char type)
{
	static char *ttab[] = { "Echo Reply", "ICMP 1", "ICMP 2", "Dest Unreachable",
		"Source Quench", "Redirect", "ICMP 6", "ICMP 7",
		"Echo", "ICMP 9", "ICMP 10", "Time Exceeded",
		"Param Problem", "Timestamp", "Timestamp Reply", "Info Request",
		"Info Reply"
	};

	if (type > 16)
		return ("OUT-OF-RANGE");
	return (ttab[type]);
}

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
	ft_strncpy(probe->hostip, inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr), INET_ADDRSTRLEN);
	/*printf("type= %d, code= %d, -> %s\n", type, code, get_icmp_type(type));*/
	if (ft_strequ(previous_probe, probe->hostip))
		return (DUPLICATE);
	ft_strncpy(previous_probe, inet_ntoa(*(struct in_addr *)&ip->ip_src.s_addr), INET_ADDRSTRLEN);
	if ((type == ICMP_TIMXCEED && code == ICMP_TIMXCEED_INTRANS) || type == ICMP_UNREACH)
	{
		return (1);
	}
	else if (code == ICMP_UNREACH_PORT)
		return (DONE_PACK);
	return (0);
}
