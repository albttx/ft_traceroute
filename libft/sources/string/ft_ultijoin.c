/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultijoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:39:38 by ale-batt          #+#    #+#             */
/*   Updated: 2016/08/30 14:02:58 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

/*
** Utilisation avec une valeur NULL en fin de parametre
*/

char	*ft_ultijoin(char *str, ...)
{
	va_list	ap;
	char	*tmp;
	char	*cpy;
	int		lol;

	lol = 0;
	va_start(ap, str);
	while (42)
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
			break ;
		cpy = ft_strdup(str);
		if (lol++ > 0)
			free(str);
		str = ft_strjoin(cpy, tmp);
		free(cpy);
	}
	va_end(ap);
	return (str);
}
