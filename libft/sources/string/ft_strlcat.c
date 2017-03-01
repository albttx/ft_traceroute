/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:11:54 by world42           #+#    #+#             */
/*   Updated: 2013/11/29 18:05:19 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = ft_strlen(dst);
	if (size < index)
		return (size + ft_strlen(src));
	while (*src && index < size - 1)
	{
		dst[index] = *src;
		src++;
		++index;
	}
	dst[index] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
