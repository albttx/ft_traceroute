/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 01:03:45 by world42           #+#    #+#             */
/*   Updated: 2013/12/23 14:27:59 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

void	ft_putbase(long l, int base, char *letters)
{
	if (l == LONG_MIN)
	{
		ft_putbase(l / base, base, letters);
		ft_putbase(-(l % base), base, letters);
	}
	else if (l < 0 && l != LONG_MIN)
	{
		ft_putchar('-');
		ft_putbase(-l, base, letters);
	}
	else if (l >= base)
	{
		ft_putbase(l / base, base, letters);
		ft_putbase(l % base, base, letters);
	}
	else
		ft_putchar(letters[l]);
}
