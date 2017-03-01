/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:49:09 by world42           #+#    #+#             */
/*   Updated: 2014/04/27 03:44:14 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_babylon(double a, double x)
{
	return (0.5 * ((a / x) + x));
}

static double	ft_fixed_point(double a, double epsilon, int nbtest)
{
	double		guess;
	double		tmp;
	int			i;

	i = 0;
	guess = 1.0;
	while (i < nbtest)
	{
		tmp = ft_absl(ft_babylon(a, guess) - guess);
		if (tmp < epsilon)
			return (guess);
		else
			guess = ft_babylon(a, guess);
		++i;
	}
	return (guess);
}

double			ft_sqrt(double x)
{
	if (x <= 0)
		return (0);
	x = (ft_fixed_point(x, EPSILON, 200));
	return (x < 0 ? 0 : x);
}
