/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:51:45 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/13 11:52:43 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

char		*get_icmp_type(unsigned char type)
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
