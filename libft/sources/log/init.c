/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:36:34 by ale-batt          #+#    #+#             */
/*   Updated: 2016/12/14 12:49:36 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_log.h"

void	log_init(char *logfile)
{
	log_singleton(logfile);
}

void	log_done(void)
{
	log_singleton(CLOSE);
}

t_log	*log_singleton(char *path)
{
	static t_log	log = {LOCK_DEFAULT_FD, 0};

	if (log.flags & FLAG_ENABLE && path != NULL)
	{
		puts("coucou");
		log.fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else if (ft_strequ(path, "CLOSE"))
		close(log.fd);
	return (&log);
}

int		log_getfd(void)
{
	t_log	*log;

	log = log_singleton(NULL);
	return (log->fd);
}

void	log_lock(int status)
{
	static int	queue = 0;
	int			place;

	return ;
	if (status == UNLOCK)
		queue--;
	else
	{
		place = ++queue;
		while (place != 1)
			;
		queue--;
	}
}
