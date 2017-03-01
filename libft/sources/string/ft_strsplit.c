/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 03:43:26 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:43:51 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_strlen_char(const char *s, char c)
{
	if (*s && *s != c)
		return (ft_strlen_char(s + 1, c) + 1);
	return (0);
}

static int	ft_tablen_word(const char *s, char c)
{
	if (!*s)
		return (1);
	if (*s != c)
		return (ft_tablen_word(s + 1, c));
	while (*s && *s == c)
		s++;
	return (ft_tablen_word(s, c) + 1);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		size;
	int		index;

	if (!s)
		return (NULL);
	size = ft_tablen_word(s, c) + 1;
	tab = (char**)malloc(sizeof(char*) * size);
	if (!tab)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			size = ft_strlen_char(s, c);
			tab[index++] = ft_strsub(s, 0, size);
			s += size;
		}
		else
			++s;
	}
	tab[index] = NULL;
	return (tab);
}
