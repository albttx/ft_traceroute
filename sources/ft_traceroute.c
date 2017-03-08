/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/08 18:49:18 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void		send_probe(t_env *env, int ttl, int seq)
{
	struct sockaddr_in	to;
	t_opacket			op;
	int					ret;

	ft_bzero(&to, sizeof(to));
	to.sin_family = AF_INET;
	to.sin_addr.s_addr = inet_addr(env->hostip);
	to.sin_port = env->port;

	ft_bzero(&op, sizeof(op));
	(op.ip).ip_off = 0;
	(op.ip).ip_hl = sizeof(op.ip) >> 2;
	(op.ip).ip_p = IPPROTO_UDP;
	(op.ip).ip_len = env->datalen;
	(op.ip).ip_ttl = ttl;
	(op.ip).ip_v = IPVERSION;
	(op.ip).ip_id = htons(env->id + seq);
	(op.ip).ip_tos = 0;
	(op.ip).ip_dst = to.sin_addr;

	(op.udp).uh_sport = htons(env->id);
	(op.udp).uh_dport = (env->port + seq);
	(op.udp).uh_ulen = htons((unsigned short)env->datalen - sizeof(struct ip));
	(op.udp).uh_sum = 0;

	(op.seq) = seq;
	(op.ttl) = ttl;

	gettimeofday(&op.tv, NULL);

	ret = sendto(env->send_sock, (char *)&op, env->datalen, 0, (struct sockaddr *)&to, sizeof(to));
	if (ret < 0 || ret != env->datalen)
	{
		perror("sendto");
	}
}

int		recv_probe(t_env *env)
{
	char				packet[512];
	ssize_t				cc;
	struct sockaddr_in	from;
	socklen_t			fromlen;

	ft_bzero(&packet, sizeof(packet));
	ft_bzero(&from, sizeof(from));
	fromlen = sizeof(from);
	cc = 0;

	fd_set				fds;
	FD_ZERO(&fds);
	FD_SET(env->recv_sock, &fds);
	struct timeval wait;
	wait.tv_sec = 2;
	wait.tv_usec = 0;

	if (select(env->recv_sock + 1, &fds, 0, 0, &wait) > 0)
	{
		cc = recvfrom(env->recv_sock, (char *)packet, sizeof(packet), 0, (struct sockaddr *)&from, &fromlen);
		if (cc < 0)
			perror("recvfrom");
		/*printf("cc = %ld\n", cc);*/
		print_probe(cc, packet, &from);
	}
	return (cc);
}

int		traceroute(t_env *env)
{
	int		seq;
	int		probe;

	create_socket(env);
 	printf("traceroute to %s (%s), ", env->hostname, env->hostip);
	printf("%d hops max, %d byte packets\n", env->max_hops, env->datalen);

	seq = -1;
	printf("ttl start = %d \n", env->ttl);
	while (env->ttl++ <= MAX_TTL)
	{
		/*puts("--------------");*/
		for (probe = 0; probe < 3; probe++)
		{
			send_probe(env, env->ttl, ++seq);
			if (recv_probe(env) <= 0)
			{
				ft_putstr(" *");
			}
			else
			{
				break ;
			}
		}
		ft_putchar('\n');
	}
	return (1);
}
