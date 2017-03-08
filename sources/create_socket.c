/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_socket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:17:27 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/08 16:43:09 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static void		set_socket_options(t_env *env)
{
	int		on;

	on = 1;
	/*setsockopt(env->send_sock, SOL_SOCKET, SO_DONTROUTE, (char *)&on, sizeof(on));*/
	/*setsockopt(env->send_sock, IPPROTO_IP, IP_TTL, &(env->ttl), sizeof(env->ttl));*/
	/*setsockopt(env->recv_sock, IPPROTO_IP, IP_RECVTTL, &on, sizeof(on));*/
}

static void		bind_socket(t_env *env)
{
	int					ret;
	struct sockaddr_in	sin;

	printf("hostname %s\n", env->hostname);
	printf("hostip %s\n", env->hostip);

	ft_bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(env->hostip);
	sin.sin_port = 0;

	/*ret = bind(env->send_sock, (struct sockaddr *)&sin, sizeof(sin));*/
	/*if (ret < 0)*/
	/*{*/
		/*perror("bind");*/
		/*exit(EXIT_FAILURE);*/
	/*}*/
}

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
	/*set_socket_options(env);*/
	bind_socket(env);
}
