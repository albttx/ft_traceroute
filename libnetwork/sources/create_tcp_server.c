/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tcp_server.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:32:02 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 15:54:01 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

static int		create_ipv4(int port, struct protoent *proto)
{
	int					sock;
	struct sockaddr_in	sin;

	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
	{
		perror("create_tcp_server: socket() IPV4");
		return (-1);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr*)&sin, sizeof(sin)))
	{
		perror("create_tcp_server: bind() IPV4");
		return (-1);
	}
	return (sock);
}

static int		create_ipv6(int port, struct protoent *proto)
{
	int					sock;
	int					on;
	struct sockaddr_in6	sin;

	sock = socket(PF_INET6, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
	{
		perror("create_tcp_server: socket() IPV6");
		return (-1);
	}
	on = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)))
	{
		perror("create_tcp_server: setsockopt() IPV6");
		return (-1);
	}
	sin.sin6_family = AF_INET6;
	sin.sin6_port = htons(port);
	sin.sin6_addr = in6addr_any;
	if (bind(sock, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
	{
		perror("create_tcp_server: bind() IPV6");
		return (-1);
	}
	return (sock);
}

int				create_tcp_server(int port, int ipv_protocol)
{
	int					sock;
	struct protoent		*proto;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	if (ipv_protocol == IPV6)
		sock = create_ipv6(port, proto);
	else
		sock = create_ipv4(port, proto);
	listen(sock, 42);
	return (sock);
}
