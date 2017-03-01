/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matchlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:24:47 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:49:44 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_starskip(const char *m, size_t *m_i)
{
	while (m[(*m_i) + 1] == '*')
		++(*m_i);
}

static void		ft_starmatch(char *s, char *m, size_t *s_i, size_t *m_i)
{
	if (s[(*s_i)] && m[(*m_i) + 1] != s[(*s_i) + 1])
		++(*s_i);
	else
	{
		++(*m_i);
		++(*s_i);
	}
}

size_t			ft_matchlen(const char *str, const char *match)
{
	size_t	m_i;
	size_t	s_i;

	m_i = 0;
	s_i = 0;
	while (match[m_i])
	{
		if (str[s_i] == match[m_i])
		{
			++m_i;
			++s_i;
		}
		else if (match[m_i] == '*')
		{
			ft_starskip(match, &m_i);
			if (!match[(m_i) + 1])
				return ((s_i) + ft_strlen(str + s_i));
			else if (!str[s_i])
				return (0);
			ft_starmatch((char*)str, (char*)match, &s_i, &m_i);
		}
		else
			return (0);
	}
	return (s_i);
}
