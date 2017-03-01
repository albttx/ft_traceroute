/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:32:18 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:37:17 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *)s1;
	src = (char *)s2;
	if (n)
	{
		while (n != '\0')
		{
			*dest = *src;
			dest++;
			src++;
			if (*(src - 1) == c)
			{
				return (dest);
			}
			n--;
		}
	}
	return (NULL);
}
