/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 11:02:30 by ale-batt          #+#    #+#             */
/*   Updated: 2016/08/30 13:51:37 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llstfree(t_llist *lst)
{
	t_llist	*tmp;

	tmp = lst;
	while (tmp)
	{
		lst = tmp;
		tmp = tmp->next;
		free(lst->content);
		free(lst);
	}
}
