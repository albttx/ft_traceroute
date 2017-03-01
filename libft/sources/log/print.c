/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:52:05 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/06 15:11:44 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_log.h"
#include <stdarg.h>

void	log_print(char *str, ...)
{
	t_log	*log;
	va_list	ap;

	log = log_singleton(NULL);
	if (log->fd == -1)
		return ;
	va_start(ap, str);
	ft_multiputs_args(log->fd, str, &ap);
}

void	log_println(char *str, ...)
{
	t_log	*log;
	va_list	ap;

	log = log_singleton(NULL);
	if (log->fd == -1)
		return ;
	va_start(ap, str);
	ft_multiputs_args(log->fd, str, &ap);
	ft_putchar_fd('\n', log->fd);
}
