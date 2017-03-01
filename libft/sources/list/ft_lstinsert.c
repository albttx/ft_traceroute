/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 01:22:01 by world42           #+#    #+#             */
/*   Updated: 2013/12/28 04:51:51 by world42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstinsert(t_list **lst, t_list *new, int (*cmpf)(void*, void*))
{
	if (*lst == NULL)
		*lst = new;
	else if (cmpf((*lst)->content, new->content) == 0)
	{
		(*lst)->content = new->content;
		free(new);
		return (*lst);
	}
	else
		return (ft_lstinsert(&((*lst)->next), new, cmpf));
	return (*lst);
}
