/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:31:29 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/13 14:28:33 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

#define SOCK_MAX_PKG_SIZE 32767

void	sock_read(const int sock)
{
	size_t	ret;
	char	buff[SOCK_MAX_PKG_SIZE + 1];

	ret = 1;
	while (ret > 0)
	{
		ft_bzero(buff, SOCK_MAX_PKG_SIZE + 1);
		ret = recv(sock, buff, SOCK_MAX_PKG_SIZE, 0);
		if (ret == 0)
		{
			perror("sock_read");
			break ;
		}
		if (buff[0] == EOT)
			break ;
		if (buff[ret - 1] == EOT)
		{
			ft_putstr(buff);
			break ;
		}
		ft_putstr(buff);
	}
}

int		sock_send_eot(const int sock)
{
	char	eot;
	int		ret;

	eot = EOT;
	ret = send(sock, &eot, 1, 0);
	if (ret <= 0)
	{
		perror("sock_send_eot");
		return (-1);
	}
	return (1);
}
