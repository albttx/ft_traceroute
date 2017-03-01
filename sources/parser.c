/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:31:35 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/01 14:10:52 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static void	opt_first_ttl(t_env *env, char *str_ttl)
{
	env->ttl = ft_atoi(str_ttl);
	if (env->ttl <= 0)
	{
		printf("ft_traceroute: first ttl must be > 0\n");
		exit(EXIT_FAILURE);
	}
}

static void	opt_max_ttl(t_env *env, char *str_max_ttl)
{
	env->max_ttl = ft_atoi(str_max_ttl);
	if (env->max_ttl <= 0)
	{
		printf("ft_traceroute: max ttl must be > 0\n");
		exit(EXIT_FAILURE);
	}
}

static void	opt_max_hops(t_env *env, char *str_max_hops)
{
	env->max_hops = ft_atoi(str_max_hops);
	if (env->max_hops <= 0)
	{
		printf("ft_traceroute: max hops must be > 0\n");
		exit(EXIT_FAILURE);
	}
}

int			parse(t_env *env, char **av)
{
	int		y;

	y = 0;
	while (av[y])
	{
		if (ft_strequ(av[y], "-m"))
			opt_max_ttl(env, av[++y]);
		else if (ft_strequ(av[y], "-h"))
			opt_max_hops(env, av[++y]);
		else if (ft_strequ(av[y], "-f"))
			opt_first_ttl(env, av[++y]);
		else
		{
			env->hostip = hostname_to_ip(av[y]);
			if (env->hostip != NULL)
			{
				env->hostname = ft_strdup(av[y]);
				break ;
			}
		}
		y++;
	}
	if (env->hostip == NULL)
		return (-1);
	return (1);
}
