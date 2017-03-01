/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 05:15:55 by world42           #+#    #+#             */
/*   Updated: 2016/08/30 13:52:37 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		lst = tmp;
		tmp = tmp->next;
		free(lst->content);
		free(lst);
	}
}
