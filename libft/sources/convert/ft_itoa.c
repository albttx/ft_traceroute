/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 01:03:09 by world42           #+#    #+#             */
/*   Updated: 2016/12/09 12:37:55 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_size_chaine(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size = 1;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return ((unsigned int)size);
}

char				*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;
	long			nb_l;

	nb_l = n;
	size = ft_size_chaine(n);
	str = ft_strnew(size + 1);
	if (!str)
		return (NULL);
	if (nb_l == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb_l < 0)
	{
		str[0] = '-';
		nb_l = -nb_l;
	}
	while ((nb_l % 10) > 0 || (nb_l / 10 != 0))
	{
		str[size--] = '0' + (nb_l % 10);
		nb_l = nb_l / 10;
	}
	return (str);
}
