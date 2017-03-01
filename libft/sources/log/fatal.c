/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:34:01 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 16:34:18 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_log.h"
#include <stdarg.h>

void	log_fatal(char *str, ...)
{
	va_list	ap;
	t_log	*log;

	log = log_singleton(NULL);
	if (log->fd != 1)
		ft_putendl_color("Log Fatal error. Check logs for details", RED);
	if (log->fd == -1)
		exit(-1);
	va_start(ap, str);
	ft_putstr_fd(RED, log->fd);
	ft_multiputs_args(log->fd, str, &ap);
	ft_putendl_fd(DEFAULT, log->fd);
	exit(-1);
}
