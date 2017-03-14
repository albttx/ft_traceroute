/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:17:03 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 13:35:51 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include "libft.h"
# include "libnetwork.h"
# include <netinet/ip_icmp.h>
# include <netinet/udp.h>
# include <sys/time.h>
# include <sys/select.h>

# define MAXPACKET 65535
# define PACKET_SIZE 512

typedef struct			s_opacket
{
	struct ip			ip;
	struct udphdr		udp;
	unsigned char		seq;
	unsigned char		ttl;
	struct timeval		tv;
}						t_opacket;

typedef struct			s_probe
{
	char				packet[PACKET_SIZE];
	ssize_t				cc;
	char				hostip[INET_ADDRSTRLEN];
	struct sockaddr_in	from;
	socklen_t			fromlen;
	unsigned char		type;
	unsigned char		code;
}						t_probe;

/*
 * send_sock: UDP socket
 * recv_sock: ICMP socket
*/
typedef struct	s_env
{
	int					send_sock;
	int					recv_sock;
	char				*hostip;
	char				*hostname;
	int					id;
	int					datalen;
	int					port;
	int					ttl;
	int					max_ttl;
	int					seq;
}						t_env;

void					create_socket(t_env *env);
int						parse(t_env *env, char **av);
int						traceroute(t_env *env);

void					send_probe(t_env *env);
int						recv_probe(t_env *env, t_probe *probe);
int						verify_probe(t_env *env, t_probe *probe);
void					print_probe(t_probe *probe);
int						print_err(int type, int code);

char					*get_icmp_type(unsigned char type);
double					delta_t(struct timeval *t1, struct timeval *t2);

#endif
