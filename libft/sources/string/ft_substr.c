/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:11:51 by world42           #+#    #+#             */
/*   Updated: 2013/12/29 23:05:21 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *src, size_t pos, size_t n)
{
	char	*dest;

	dest = NULL;
	if (n > 0)
	{
		dest = (char*)malloc(sizeof(char*) * (n + 1));
		if (dest)
			ft_strncat(dest, src + pos, n);
	}
	return (dest);
}
