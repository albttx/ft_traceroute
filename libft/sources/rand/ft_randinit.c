/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 03:03:30 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:41:24 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_randinit(int seed)
{
	int	*array;
	int	i;

	if ((array = ft_getrand_array()) != NULL)
	{
		array[0] = seed;
		i = 1;
		while (i < RAND_SIZE)
		{
			array[i] = 1812433253
				* (array[i - 1] ^ (array[i - 1] >> 30))
				+ i;
			++i;
		}
		return (1);
	}
	return (0);
}
