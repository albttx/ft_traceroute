/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_transfert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:16:20 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 15:58:39 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

int			sock_send_uint32(const int sock, const uint32_t nb)
{
	uint32_t	tmp;

	tmp = htonl(nb);
	if (send(sock, &tmp, sizeof(uint32_t), 0) <= 0)
	{
		perror("sock_send_uint32");
		return (-1);
	}
	return (1);
}

uint32_t	sock_get_uint32(const int sock)
{
	uint32_t	type;

	if (recv(sock, &type, sizeof(uint32_t), 0) <= 0)
	{
		perror("sock_get_uint32");
		return (-1);
	}
	type = ntohl(type);
	return (type);
}
