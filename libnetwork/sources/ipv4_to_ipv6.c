/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv4_to_ipv6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 12:02:16 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 15:55:38 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"

static void		add_octets(char *ipv6_addr, char *ipv4_oct)
{
	int		oct;
	int		res[2];
	char	*hex;

	oct = ft_atoi(ipv4_oct);
	res[0] = oct / 16;
	res[1] = oct % 16;
	hex = ft_tohexa(res[0]);
	ft_strcat(ipv6_addr, hex);
	free(hex);
	hex = ft_tohexa(res[1]);
	ft_strcat(ipv6_addr, hex);
	free(hex);
}

char			*ipv4_to_ipv6(const char *ipv4_addr)
{
	char	*ipv6_addr;
	char	**ipv4_octs;
	int		i;

	ipv6_addr = ft_strnew(INET6_ADDRSTRLEN);
	if (get_ipvx(ipv4_addr) != IPV4)
		return (NULL);
	ipv4_octs = ft_strsplit(ipv4_addr, '.');
	i = 0;
	ft_strcpy(ipv6_addr, "0:0:0:0:0:ffff");
	while (ipv4_octs[i])
	{
		if (i % 2 == 0)
			ft_strcat(ipv6_addr, ":");
		add_octets(ipv6_addr, ipv4_octs[i]);
		i++;
	}
	ft_freetab(ipv4_octs);
	return (ipv6_addr);
}
