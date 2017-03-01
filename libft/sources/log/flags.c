/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:41:32 by ale-batt          #+#    #+#             */
/*   Updated: 2016/12/14 16:42:45 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_log.h"
#include <time.h>

void	log_printflags(t_log *log)
{
	if (log->flags & FLAG_TIME)
	{
		ft_printtime_fd(TIME_HMS, log->fd);
		ft_putstr_fd("  ", log->fd);
	}
}

void	log_setflag(t_flags flag)
{
	t_log	*log;

	log = log_singleton(NULL);
	log->flags |= flag;
}
