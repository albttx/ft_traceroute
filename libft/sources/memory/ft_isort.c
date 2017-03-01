/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 19:53:30 by world42           #+#    #+#             */
/*   Updated: 2014/02/24 20:52:06 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_isort(void *a, size_t n, size_t es, int (*cmp)(void*, void*))
{
	size_t	i;
	size_t	j;
	void	*tmp;

	i = 1;
	if ((tmp = (void*)malloc(es)) == NULL)
		return (NULL);
	while (i < n)
	{
		ft_memcpy(tmp, (char*)a + (es * i), es);
		j = i;
		while (j > 0 && cmp((char*)a + (es * (j - 1)), tmp) > 0)
		{
			ft_memcpy((char*)a + (es * j), (char*)a + (es * (j - 1)), es);
			--j;
		}
		ft_memcpy((char*)a + (es * j), tmp, es);
		++i;
	}
	free(tmp);
	return (a);
}
