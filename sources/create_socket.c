/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_socket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:17:27 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/01 14:06:25 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static int		set_socket_options(int sock, t_env *env)
{
	int		on;

	on = 1;
	setsockopt(sock, IPPROTO_IP, IP_RECVTTL, &on, sizeof(on));
	setsockopt(sock, IPPROTO_IP, IP_TTL, &(env->ttl), sizeof(env->ttl));
	return (sock);
}

int				create_socket(t_env *env)
{
	int					sock;

	sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sock == -1)
	{
		perror("create_socket: socket()");
		exit(EXIT_FAILURE);
	}
	return (set_socket_options(sock, env));
}
