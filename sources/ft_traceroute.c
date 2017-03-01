/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/01 14:14:28 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		traceroute(t_env *env)
{
	env->sock = create_socket(env);
	printf("traceroute to %s (%s), ", env->hostname, env->hostip);
	printf("%d hops max, %d byte packets\n", env->max_hops, env->packet_size);
	return (1);
}
