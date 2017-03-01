/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tcp_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:22:45 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 15:30:12 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

static int		client_tcp_ipv6(char *addr, int port, struct protoent *proto)
{
	int						sock;
	struct hostent			*s;
	struct sockaddr_in6		sin;

	s = gethostbyname2(addr, AF_INET6);
	if (!s)
	{
		perror("create_tcp_client: gethostbyname2()");
		return (-1);
	}
	sock = socket(PF_INET6, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
	{
		perror("[client] socket");
		return (-1);
	}
	sin.sin6_family = AF_INET6;
	sin.sin6_port = htons(port);
	memmove((char *)&sin.sin6_addr.s6_addr, (char *)s->h_addr, s->h_length);
	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		perror("create_tcp_client: connect()");
		exit(EXIT_FAILURE);
	}
	return (sock);
}

static int		client_tcp_ipv4(char *addr, int port, struct protoent *proto)
{
	int						sock;
	struct hostent			*s;
	struct sockaddr_in		sin;

	s = gethostbyname2(addr, AF_INET);
	if (!s)
	{
		perror("create_tcp_client: gethostbyname2()");
		return (-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
	{
		perror("create_tcp_client: socket()");
		return (-1);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		perror("create_tcp_client: connect()");
		exit(EXIT_FAILURE);
	}
	return (sock);
}

int				create_tcp_client(char *addr, int port)
{
	int					sock;
	int					ipvx;
	struct protoent		*proto;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	ipvx = get_ipvx(addr);
	if (ipvx == IPV6)
		sock = client_tcp_ipv6(addr, port, proto);
	else if (ipvx == IPV4)
		sock = client_tcp_ipv4(addr, port, proto);
	else
	{
		printf("create_tcp_client(): Error creating tcp\n");
		return (-1);
	}
	return (sock);
}
