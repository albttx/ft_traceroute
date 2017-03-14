/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 16:02:48 by ale-batt         ###   ########.fr       */
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

	for (; env->ttl < env->max_ttl; env->ttl++)
	{
		ret = 0;
		printf("%2d ", env->ttl);
		gettimeofday(&t1, NULL);
		for (nprobes = 0; nprobes < env->nqueries; nprobes++)
		{
			ft_bzero(&probe, sizeof(probe));
			send_probe(env);
			recv_probe(env, &probe);
			gettimeofday(&t2, NULL);
			ret += verify_probe(env, &probe);
			if (ret == 0)
				printf(" *");
			else
			{
				print_probe(&probe);
				printf(" %g ms", delta_t(&t1, &t2));
			}
			(void)fflush(stdout);
		}
		printf("\n");
		if (ret > env->nqueries)
			break ;
	}
	return (1);
}
