/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matchsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 02:04:50 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:36:23 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_word_count(const char *s, const char *m)
{
	int		i;
	size_t	size;

	i = 0;
	while (*s)
	{
		if ((size = ft_matchlen(s, m)) > 0)
		{
			++i;
			s += size;
		}
		else
			++s;
	}
	return (i);
}

char		**ft_matchsplit(const char *str, const char *match)
{
	char	**tab;
	int		size;
	int		tab_i;

	if (!str)
		return (NULL);
	size = ft_word_count(str, match) + 1;
	tab = (char**)malloc(sizeof(char*) * size);
	if (!tab)
		return (NULL);
	tab_i = 0;
	while (*str)
	{
		if ((size = ft_matchlen(str, match)) > 0)
		{
			tab[tab_i++] = ft_strsub(str, 0, size);
			str += size;
		}
		else
			++str;
	}
	tab[tab_i] = NULL;
	return (tab);
}
