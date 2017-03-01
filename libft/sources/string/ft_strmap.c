/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:34:17 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:43:30 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	index;

	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		ft_strcpy(str, s);
		if (str == NULL)
			return (NULL);
		index = 0;
		while (str[index])
		{
			str[index] = (*f)(str[index]);
			++index;
		}
		return (str);
	}
	return (NULL);
}
