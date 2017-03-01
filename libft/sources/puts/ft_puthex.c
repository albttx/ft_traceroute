/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 06:24:28 by world42           #+#    #+#             */
/*   Updated: 2013/12/10 06:29:44 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long l)
{
	if (l >= 16)
	{
		ft_puthex(l / 16);
		ft_puthex(l % 16);
	}
	else
		ft_putchar(HEX[l]);
}
