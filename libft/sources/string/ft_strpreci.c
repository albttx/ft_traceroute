/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpreci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:50:44 by ale-batt          #+#    #+#             */
/*   Updated: 2017/01/03 15:03:14 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpreci(char *str, char c, int preci)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (len >= preci)
		return (str);
	tmp = ft_strdup(str);
	ft_memset(str, c, preci);
	ft_strncpy(str + (preci - len), tmp, len);
	free(tmp);
	return (str);
}
