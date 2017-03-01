/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 00:22:50 by world42           #+#    #+#             */
/*   Updated: 2016/12/21 13:57:24 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_tabjoin(char **tab)
{
	char	*str;

	str = NULL;
	if (tab)
	{
		while (*tab)
		{
			str = (str) ? ft_strfljoin(str, *tab) : ft_strdup(*tab);
			++tab;
		}
	}
	return (str);
}
