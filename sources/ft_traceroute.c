/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:56 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/03 18:08:03 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void		send_probe(t_env *env, int ttl, int seq)
{
	struct sockaddr		from;
	t_opacket			op;
	int					ret;

	ft_bzero(&op, sizeof(op));
	(op.ip).ip_off = 0;
	(op.ip).ip_hl = sizeof(op.ip) >> 2;
	(op.ip).ip_p = IPPROTO_UDP;
	(op.ip).ip_len = env->datalen;
	(op.ip).ip_ttl = ttl;
	(op.ip).ip_v = IPVERSION;
	(op.ip).ip_id = htons(env->id);

	(op.udp).uh_sport = htons(env->id);
	(op.udp).uh_dport = (env->port + seq);
	(op.udp).uh_ulen = htons((unsigned short)env->datalen - sizeof(struct ip));
	(op.udp).uh_sum = 0;

	(op.seq) = seq;
	(op.ttl) = ttl;
	ft_bzero(&from, sizeof(from));
	ret = sendto(env->sock, (char *)&op, env->datalen, 0, (struct sockaddr *)&from, sizeof(from));
	if (ret < 0 || ret != env->datalen)
	{
		perror("sendto");
	}
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
	cc = recvfrom(env->sock, (char *)packet, sizeof(packet), 0, (struct sockaddr *)&from, &fromlen);
	if (cc < 0)
		perror("recvfrom");
}

int		traceroute(t_env *env)
{
	int		seq;

	env->sock = create_socket(env);
 	printf("traceroute to %s (%s), ", env->hostname, env->hostip);
	printf("%d hops max, %d byte packets\n", env->max_hops, env->datalen);

	seq = -1;
	{
		send_probe(env, 1, ++seq);
		recv_probe(env);
	}
	return (1);
}
