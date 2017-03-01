/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 19:47:19 by world42           #+#    #+#             */
/*   Updated: 2013/11/29 19:49:02 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
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
			str[index] = (*f)(index, str[index]);
			++index;
		}
		return (str);
	}
	return (NULL);
}
