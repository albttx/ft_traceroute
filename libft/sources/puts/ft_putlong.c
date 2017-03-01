/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 23:41:08 by world42           #+#    #+#             */
/*   Updated: 2013/12/29 23:01:06 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

void	ft_putlong(long l)
{
	if (l == LONG_MIN)
	{
		ft_putnbr(l / 10);
		ft_putnbr(-(l % 10));
	}
	else if (l < 0 && l != LONG_MIN)
	{
		ft_putchar('-');
		ft_putnbr(-l);
	}
	else if (l >= 10)
	{
		ft_putnbr(l / 10);
		ft_putnbr(l % 10);
	}
	else
		ft_putchar(l + '0');
}
