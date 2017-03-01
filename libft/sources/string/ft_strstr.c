/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:26:33 by world42           #+#    #+#             */
/*   Updated: 2013/12/29 23:04:50 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i1])
	{
		i2 = 0;
		while (s1[i1 + i2] && s2[i2] && s2[i2] == s1[i1 + i2])
			i2++;
		if (!s2[i2])
			return (char*)(s1 + i1);
		i1++;
	}
	return (NULL);
}
