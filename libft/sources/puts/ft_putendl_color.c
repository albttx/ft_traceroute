/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:49:45 by ale-batt          #+#    #+#             */
/*   Updated: 2016/08/30 14:26:05 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_color(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(DEFAULT);
	ft_putchar('\n');
}
