/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:17:03 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/01 14:14:09 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

#include "libft.h"
#include "libnetwork.h"

typedef struct	s_env
{
	int			sock;
	char		*hostip;
	char		*hostname;
	int			ttl;
	int			max_ttl;
	int			max_hops;
	int			packet_size;
}				t_env;

int				create_socket(t_env *env);
int				parse(t_env *env, char **av);
int				traceroute(t_env *env);

#endif
