/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 03:07:57 by world42           #+#    #+#             */
/*   Updated: 2013/12/05 00:13:58 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(const char *str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(*ret) * (ft_strlen(str) + 1));
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		while (*str != '\0')
		{
			ret[i] = *str++;
			i++;
		}
		ret[i] = '\0';
		while (ret[i - 1] == ' ' || ret[i - 1] == '\t' || ret[i - 1] == '\n')
		{
			ret[i - 1] = '\0';
			i--;
		}
	}
	return (ret);
}
