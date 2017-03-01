/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:26:33 by world42           #+#    #+#             */
/*   Updated: 2013/12/29 23:04:15 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	len1;
	size_t	tmp;

	len = ft_strlen(s2);
	len1 = ft_strlen(s1);
	tmp = 0;
	if (!s2)
		return (char*)(s1);
	while (tmp + len <= n && tmp + len <= len1)
	{
		if (!ft_strncmp(s1, s2, len))
			return ((char*)s1);
		s1++;
		tmp++;
	}
	return (NULL);
}
