/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:39:09 by world42           #+#    #+#             */
/*   Updated: 2013/12/29 23:03:36 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	index;

	index = ft_strlen(s1);
	while (*s2 && n)
	{
		s1[index] = *s2;
		s2++;
		++index;
		--n;
	}
	s1[index] = '\0';
	return (s1);
}
