/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipvx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:30:15 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 19:15:55 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

int		get_ipvx(const char *addr)
{
	if (addr && gethostbyname2(addr, AF_INET))
		return (IPV4);
	else if (addr && gethostbyname2(addr, AF_INET6))
		return (IPV6);
	else
	{
		printf("get_ipvx(): addr: [%s] addr not well formated\n", addr);
		return (-1);
	}
}
