/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_probe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:15:28 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/14 12:34:06 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		recv_probe(t_env *env, t_probe *probe)
{
	int					s;
	fd_set				fds;
	struct timeval		wait;

	ft_bzero(probe, sizeof(*probe));
	/*ft_bzero(&probe->packet, sizeof(probe->packet));*/
	/*ft_bzero(&probe->from, sizeof(probe->from));*/
	probe->fromlen = sizeof(probe->from);
	probe->cc = 0;

	FD_ZERO(&fds);
	FD_SET(env->recv_sock, &fds);
	wait.tv_sec = 1;
	wait.tv_usec = 500;

	if (select(env->recv_sock + 1, &fds, (fd_set *)0, (fd_set *)0, &wait) > 0)
	{
		probe->cc = recvfrom(env->recv_sock, (char *)probe->packet, sizeof(probe->packet),
				0, (struct sockaddr *)&probe->from, &probe->fromlen);
		if (probe->cc < 0)
			perror("recvfrom");
	}
	return (probe->cc);
}
