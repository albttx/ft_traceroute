/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_probe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:15:28 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/09 15:16:55 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		recv_probe(t_env *env)
{
	char				packet[512];
	ssize_t				cc;
	struct sockaddr_in	from;
	socklen_t			fromlen;
	struct timeval		wait;
	fd_set				fds;

	ft_bzero(&packet, sizeof(packet));
	ft_bzero(&from, sizeof(from));
	fromlen = sizeof(from);
	cc = 0;

	FD_ZERO(&fds);
	FD_SET(env->recv_sock, &fds);
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


