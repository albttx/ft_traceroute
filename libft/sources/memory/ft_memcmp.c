/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:21:05 by world42           #+#    #+#             */
/*   Updated: 2014/03/09 17:12:31 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	s1_tmp = ((unsigned char*)s1);
	s2_tmp = ((unsigned char*)s2);
	while (n--)
	{
		if (*s1_tmp != *s2_tmp)
			return (*s1_tmp - *s2_tmp);
		++s1_tmp;
		++s2_tmp;
	}
	return (0);
}
