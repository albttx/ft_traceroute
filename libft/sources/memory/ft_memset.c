/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:56:48 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:39:38 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			tmp;
	unsigned char	*b_tmp;

	tmp = 0;
	b_tmp = (unsigned char*)b;
	while (tmp != len)
	{
		*(b_tmp + tmp) = (unsigned char)c;
		++tmp;
	}
	return (b_tmp);
}
