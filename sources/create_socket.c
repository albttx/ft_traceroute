/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_socket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:17:27 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 16:04:26 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void		create_socket(t_env *env)
{
	env->send_sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if (env->send_sock < 0)
	{
		perror("socket(): send_sock");
		exit(EXIT_FAILURE);
	}
	env->recv_sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (env->recv_sock < 0)
	{
		perror("socket(): recv_sock");
		exit(EXIT_FAILURE);
	}
}
