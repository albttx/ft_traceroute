/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:42:44 by world42           #+#    #+#             */
/*   Updated: 2013/11/29 18:07:32 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	tmp = 0;
	while (tmp != n && s2[tmp])
	{
		s1[tmp] = s2[tmp];
		tmp++;
	}
	while (tmp != n)
	{
		s1[tmp] = '\0';
		tmp++;
	}
	return (s1);
}
