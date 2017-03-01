/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:17:17 by ale-batt          #+#    #+#             */
/*   Updated: 2016/12/11 19:21:35 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"
#include <time.h>

static char		*ft_gettime(char *format)
{
	char		*buff;
	time_t		now;
	struct tm	*stm;

	buff = ft_strnew(20);
	now = time(0);
	stm = gmtime(&now);
	strftime(buff, sizeof(buff), format, stm);
	return (buff);
}

void			ft_printtime(char *format)
{
	char	*time;

	time = ft_gettime(format);
	ft_putstr(time);
	free(time);
}

void			ft_printtime_fd(char *format, int fd)
{
	char	*time;

	time = ft_gettime(format);
	ft_putstr_fd(time, fd);
	free(time);
}
