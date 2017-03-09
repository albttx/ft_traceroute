/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/09 19:19:39 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		traceroute(t_env *env)
{
	t_probe probe;
	int		nprobes;
	int		ret;

	create_socket(env);
 	printf("traceroute to %s (%s), ", env->hostname, env->hostip);
	printf("%d hops max, %d byte packets\n", env->max_ttl, env->datalen);

	env->ttl--;
	while (env->ttl++ <= env->max_ttl)
	{
		puts("--------------");
		printf("%2d ", env->ttl);
		for (nprobes = 0; nprobes < 3; nprobes++)
		{
			ft_bzero(&probe, sizeof(probe));
			send_probe(env);
			recv_probe(env, &probe);
			ret = verify_probe(env, &probe);
			if (ret == 1)
			{
				print_probe(&probe);
				/*break ;*/
			}
			else if (ret == 42)
				return (1);
			else if (ret == 0)
				printf(" *");
			(void)fflush(stdout);
		}
		if (nprobes > 1 && ret == 0)
			printf("\n");
	}
	return (1);
}
