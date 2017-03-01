/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:59:05 by world42           #+#    #+#             */
/*   Updated: 2016/12/12 18:59:04 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	s2 = NULL;
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		++i;
	}
	return (s2);
}

char	*ft_strfdup(char *s1)
{
	char		*s2;

	s2 = ft_strdup(s1);
	free(s1);
	return (s2);
}
