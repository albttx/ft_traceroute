/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:17:03 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/03 16:15:15 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

#include "libft.h"
#include "libnetwork.h"
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>

# define MAXPACKET 65535

typedef struct		s_opacket
{
	struct ip		ip;
	struct udphdr	udp;
	unsigned char	seq;
	unsigned char	ttl;
	struct timeval	tv;
}					t_opacket;

typedef struct	s_env
{
	int			sock;
	char		*hostip;
	char		*hostname;
	int			id;
	int			datalen;
	int			port;
	int			ttl;
	int			max_ttl;
	int			max_hops;
}				t_env;

int				create_socket(t_env *env);
int				parse(t_env *env, char **av);
int				traceroute(t_env *env);

#endif
