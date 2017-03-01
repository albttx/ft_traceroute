/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_bin_protocol.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:16:06 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/09 14:46:40 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

int		sock_send(const int sock, uint32_t size, const char *msg)
{
	int			ret[2];
	uint32_t	nsize;

	nsize = htonl(size);
	ret[0] = send(sock, &nsize, sizeof(uint32_t), 0);
	ret[1] = send(sock, msg, (size_t)size, 0);
	if (ret[0] <= 0 || ret[1] <= 0)
	{
		perror("sock_send");
		return (-1);
	}
	return (1);
}

char	*sock_recv(const int sock)
{
	char		*msg;
	int			ret[2];
	uint32_t	hsize;
	uint32_t	size;

	ret[0] = recv(sock, &hsize, sizeof(uint32_t), 0);
	size = htonl(hsize);
	msg = ft_strnew(size + 1);
	ret[1] = recv(sock, msg, (size_t)size, 0);
	if (ret[0] <= 0 || ret[1] <= 0)
	{
		perror("sock_recv");
		return (NULL);
	}
	return (msg);
}
