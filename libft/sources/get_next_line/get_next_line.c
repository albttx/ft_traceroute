/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:16:35 by world42           #+#    #+#             */
/*   Updated: 2016/10/26 18:41:55 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_push(int const fd, char **buf, char **line)
{
	int			i;
	char		*split;

	i = 0;
	while (buf[1][i] != '\0' && buf[1][i] != '\n')
		i++;
	split = ft_strsub(buf[1], 0, i);
	*line = ft_strjoin(*line, split);
	free(split);
	buf[1] += i;
	if (!*buf[1] || buf[0][BUFF_SIZE] != '\0')
		return (ft_read(fd, buf, line));
	++buf[1];
	return (1);
}

int		ft_read(int const fd, char **buf, char **line)
{
	char		*old;
	ssize_t		ret;

	if (!buf[1] || !*buf[1])
	{
		buf[1] = buf[0];
		ft_bzero(buf[0], BUFF_SIZE);
		ret = read(fd, buf[0], BUFF_SIZE);
	}
	if (*buf[0])
	{
		old = *line;
		ret = ft_push(fd, buf, line);
		free(old);
	}
	if (ret == 0 && **line)
		return (1);
	return (ret < 0 ? -1 : ret > 0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf[2];

	if (!buf[0])
		buf[0] = ft_strnew(BUFF_SIZE + 1);
	if (buf[0] && (*line = ft_strnew(2)) != NULL)
		return (ft_read(fd, buf, line));
	return (-1);
}
