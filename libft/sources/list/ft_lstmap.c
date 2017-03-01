/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoustai <mmoustai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 21:26:47 by mmoustai          #+#    #+#             */
/*   Updated: 2013/12/01 18:36:32 by mmoustai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lst1;
	t_list		*lst2;

	lst2 = (t_list *)malloc(sizeof(t_list));
	lst1 = lst2;
	while (lst != NULL)
	{
		if ((lst1->next = f(lst)) == NULL)
			return (NULL);
		lst = lst->next;
		lst1 = lst1->next;
	}
	return (lst2->next);
}
