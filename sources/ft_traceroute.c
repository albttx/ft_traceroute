/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 13:51:12 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		traceroute(t_env *env)
{
	t_probe 		probe;
	int				nprobes;
	int				ret;
	struct timeval	t1;
	struct timeval	t2;

	create_socket(env);
	fprintf(stderr, "traceroute to %s (%s)", env->hostname, env->hostip);
	fprintf(stderr, ", %d hops max, %d byte packets\n", env->max_ttl, env->datalen);

	for (env->ttl = 1; env->ttl < env->max_ttl; env->ttl++)
	{
		puts("--------------");
		printf("%2d  ", env->ttl);
		gettimeofday(&t1, NULL);
		for (nprobes = 0; nprobes < 3; nprobes++)
		{
			ft_bzero(&probe, sizeof(probe));
			send_probe(env);
			recv_probe(env, &probe);
			gettimeofday(&t2, NULL);
			ret = verify_probe(env, &probe);
			if (ret == 0)
			{
				printf(" *");
			}
			else if (ret == 1)
			{
				print_probe(&probe);
				printf(" %g ms ", delta_t(&t1, &t2));
			}
			else if (ret == 42)
			{
				print_probe(&probe);
				printf("\n");
				return (1);
			}
			(void)fflush(stdout);
		}
		printf("\n");
	}
	return (1);
}
