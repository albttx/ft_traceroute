/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 23:22:40 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/06 15:12:10 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_log.h"
#include <stdarg.h>

void	log_error(char *str, ...)
{
	va_list	ap;
	t_log	*log;

	log = log_singleton(NULL);
	if (log->fd == -1)
		exit(-1);
	va_start(ap, str);
	ft_putstr_fd(RED, log->fd);
	ft_multiputs_args(log->fd, str, &ap);
	ft_putstr_fd(DEFAULT, log->fd);
}
