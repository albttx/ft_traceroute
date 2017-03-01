/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:45:40 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 16:33:54 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **src)
{
	char	**new;
	int		len;
	int		i;

	if (!src || !src[0])
		return (NULL);
	len = ft_tablen(src);
	new = (char **)malloc((sizeof(char *) * len) + 1);
	i = 0;
	while (src[i])
	{
		new[i] = ft_strdup(src[i]);
		i++;
	}
	return (new);
}
