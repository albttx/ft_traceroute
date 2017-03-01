/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:12:18 by world42           #+#    #+#             */
/*   Updated: 2013/12/29 23:26:13 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	if (!s)
		return (NULL);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[(size_t)start + i] != '\0')
	{
		str[i] = s[(size_t)start + i];
		i++;
	}
	return (str);
}
