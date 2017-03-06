/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/06 19:06:51 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void		send_probe(t_env *env, int ttl, int seq)
{
	struct sockaddr		from;
	struct sockaddr_in	tmp;
	t_opacket			op;
	int					ret;

	ft_bzero(&op, sizeof(op));
	(op.ip).ip_off = 0;
	(op.ip).ip_hl = sizeof(op.ip) >> 2;
	(op.ip).ip_p = IPPROTO_UDP;
	(op.ip).ip_len = env->datalen;
	(op.ip).ip_ttl = ttl;
	(op.ip).ip_v = IPVERSION;
	(op.ip).ip_id = htons(env->id + seq);
	(op.ip).ip_tos = 0;

	ft_bzero(&tmp, sizeof(tmp));
	tmp.sin_family = AF_INET;
	tmp.sin_addr.s_addr = inet_addr(env->hostip);
	/*(op.ip).ip_src = ;*/
	(op.ip).ip_dst = tmp.sin_addr;

	(op.udp).uh_sport = htons(env->id);
	(op.udp).uh_dport = (env->port + seq);
	(op.udp).uh_ulen = htons((unsigned short)env->datalen - sizeof(struct ip));
	(op.udp).uh_sum = 0;

	(op.seq) = seq;
	(op.ttl) = ttl;

	gettimeofday(&op.tv, NULL);

	ft_bzero(&from, sizeof(from));
	ret = sendto(env->send_sock, (char *)&op, env->datalen, 0, (struct sockaddr *)&from, sizeof(from));
	if (ret < 0 || ret != env->datalen)
	{
		perror("sendto");
	}
	/*printf("sendto: %d\n", ret);*/
}

void	recv_probe(t_env *env)
{
	char				packet[512];
	ssize_t				cc;
	struct sockaddr_in	from;
	socklen_t			fromlen;

	ft_bzero(&packet, sizeof(packet));
	ft_bzero(&from, sizeof(from));
	fromlen = sizeof(from);

	/*fd_set				fds;*/
	/*FD_ZERO(&fds);*/
	/*FD_SET(env->recv_sock, &fds);*/
	/*struct timeval wait;*/
	/*wait.tv_sec = 2;*/
	/*wait.tv_usec = 0;*/
	/*if (select(env->send_sock + 1, &fds, 0, 0, &wait) > 0)*/
	{
		cc = recvfrom(env->recv_sock, (char *)packet, sizeof(packet), 0, (struct sockaddr *)&from, &fromlen);
		if (cc < 0)
			perror("recvfrom");
		print_probe(cc, packet, &from);
	}
}

int		traceroute(t_env *env)
{
	int		seq;

	create_socket(env);
 	printf("traceroute to %s (%s), ", env->hostname, env->hostip);
	printf("%d hops max, %d byte packets\n", env->max_hops, env->datalen);

	seq = -1;
	printf("ttl start = %d \n", env->ttl);
	while (seq < 10)
	{
		send_probe(env, env->ttl, ++seq);
		// while 0..3
		recv_probe(env);
		env->ttl += 1;
		puts("--------------");
	}
	return (1);
}
