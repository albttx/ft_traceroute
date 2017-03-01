/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strajax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 17:23:46 by ale-batt          #+#    #+#             */
/*   Updated: 2015/12/09 12:42:23 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strajax(char *str)
{
	char	*new;
	int		i;
	int		o;

	i = 0;
	o = 0;
	new = ft_strnew(ft_strlen(str) + 1);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			new[o++] = ' ';
		}
		else
			new[o++] = str[i++];
	}
	new[o] = 0;
	return (new);
}
