/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_binder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:02:37 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 15:49:24 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libnetwork.h"

int		accept_binder(int sock)
{
	int							cs;
	socklen_t					addr_len;
	struct sockaddr_storage		client_addr;

	addr_len = sizeof(client_addr);
	cs = accept(sock, (struct sockaddr*)&client_addr, &addr_len);
	if (cs == -1)
	{
		perror("accept_binder: accept()");
		return (-1);
	}
	return (cs);
}
