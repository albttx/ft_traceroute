/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_socket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:17:27 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/03 14:55:35 by ale-batt         ###   ########.fr       */
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

static void		bind_socket(int sock, t_env *env)
{
	int					ret;
	struct sockaddr_in	sin;

	ft_bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	/*sin.sin_addr.s_addr(inet_addr(env->hostip));*/
	ret = bind(sock, (struct sockaddr *)&sin, sizeof(sin));
	if (ret <= 0)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	(void)env;
}

int				create_socket(t_env *env)
{
	int					sock;

	sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
	if (sock == -1)
	{
		perror("create_socket: socket()");
		exit(EXIT_FAILURE);
	}
	env->sock = sock;
	set_socket_options(sock, env);
	return (sock);
}
