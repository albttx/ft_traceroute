/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:17:45 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/06 18:26:05 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static int	usage(char *name)
{
	printf("usage: %s [-f first ttl] [-m max ttl] [-h max hops ] host\n", name);
	return (-1);
}

static void	init(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->id = (getpid() & 0xffff) | 0x8000;
	env->hostip = NULL;
	env->hostname = NULL;
	env->ttl = 1;
	env->max_ttl = 255;
	env->max_hops = 30;
	env->port = 32768 + 666;
	env->datalen = sizeof(t_opacket);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (usage(av[0]));
	init(&env);
	if (parse(&env, av) == -1)
		return (usage(av[0]));
	traceroute(&env);
	return (0);
}
