/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_probe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:17:07 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/09 16:01:43 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static void	init(t_env *env, struct sockaddr_in *to, t_opacket *op)
{
	ft_bzero(to, sizeof(*to));
	to->sin_family = AF_INET;
	to->sin_addr.s_addr = inet_addr(env->hostip);
	to->sin_port = env->port;

	ft_bzero(op, sizeof(*op));
	(op->ip).ip_off = 0;
	(op->ip).ip_hl = sizeof(op->ip) >> 2;
	(op->ip).ip_p = IPPROTO_UDP;
	(op->ip).ip_len = env->datalen;
	(op->ip).ip_ttl = env->ttl;
	(op->ip).ip_v = IPVERSION;
	(op->ip).ip_id = htons(env->id + env->seq);
	(op->ip).ip_tos = 0;
	(op->ip).ip_dst = to->sin_addr;
	
	(op->udp).uh_sport = htons(env->id);
	(op->udp).uh_dport = (env->port + env->seq);
	(op->udp).uh_ulen = htons((unsigned short)env->datalen - sizeof(struct ip));
	(op->udp).uh_sum = 0;

	(op->seq) = env->seq;
	(op->ttl) = env->ttl;
}

void		send_probe(t_env *env)
{
	struct sockaddr_in	to;
	t_opacket			op;
	int					ret;

	env->seq++;
	init(env, &to, &op);
	gettimeofday(&op.tv, NULL);
	ret = sendto(env->send_sock, (char *)&op, env->datalen, 0, (struct sockaddr *)&to, sizeof(to));
	if (ret < 0 || ret != env->datalen)
	{
		perror("sendto");
	}
}


