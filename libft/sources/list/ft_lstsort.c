/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:02:58 by ale-batt          #+#    #+#             */
/*   Updated: 2016/11/02 14:58:04 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **list, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;

	tmp = *list;
	prev = tmp;
	while (tmp->next)
	{
		next = tmp->next;
		if (cmp(tmp->content, next->content) > 0)
		{
			tmp->next = next->next;
			if (prev != tmp)
				prev->next = next;
			next->next = tmp;
			if (*list == prev && *list == tmp)
				*list = next;
			tmp = *list;
			prev = tmp;
			continue ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
