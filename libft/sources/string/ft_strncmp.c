/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:32:21 by world42           #+#    #+#             */
/*   Updated: 2013/11/27 17:11:24 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	s1_tmp = (unsigned char*)s1;
	s2_tmp = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*s1_tmp != '\0' && *s2_tmp != '\0' && *s1_tmp == *s2_tmp && n != 0)
	{
		n--;
		if (n == 0)
			return (*s1_tmp - *s2_tmp);
		s1_tmp++;
		s2_tmp++;
	}
	return (*s1_tmp - *s2_tmp);
}
