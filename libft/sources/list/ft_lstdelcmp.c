/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 01:40:45 by world42           #+#    #+#             */
/*   Updated: 2014/01/24 17:55:09 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelcmp(t_list **root, void *ct, int (*cmpf)(void*, void*),
					void (*del)(void*, size_t))
{
	if (!*root)
		;
	else if (cmpf((*root)->content, ct) != 0)
		ft_lstdelcmp(&((*root)->next), ct, cmpf, del);
	else
		ft_lstdelone(root, del);
}
