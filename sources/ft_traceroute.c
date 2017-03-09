/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/09 15:33:37 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		traceroute(t_env *env)
{
	int		probe;
	int		cc;

	create_socket(env);
 	printf("traceroute to %s (%s), ", env->hostname, env->hostip);
	printf("%d hops max, %d byte packets\n", env->max_ttl, env->datalen);

	env->ttl--;
	while (env->ttl++ <= env->max_ttl)
	{
		puts("--------------");
		printf("%2d ", env->ttl);
		for (probe = 0; probe < 3; probe++)
		{
			send_probe(env);
			cc = recv_probe(env);
			if (cc <= 0)
			{
				printf(" *");
			}
			else
			{
				break ;
			}
			(void)fflush(stdout);
		}
		printf("\n");
	}
	return (1);
}
