/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_announcement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:24:42 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/14 13:23:17 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

int		sock_announce_protocol(const int sock, const int protocol)
{
	uint32_t	type;

	if (protocol == SIZED_PROTOCOL)
		type = htonl(SIZED_PROTOCOL);
	else
		type = htonl(LOOOP_PROTOCOL);
	return (sock_send_uint32(sock, type));
}

int		sock_get_protocol(const int sock)
{
	uint32_t	ret;

	ret = sock_get_uint32(sock);
	return ((int)ntohl(ret));
}
