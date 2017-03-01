/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 22:34:29 by world42           #+#    #+#             */
/*   Updated: 2016/08/30 13:44:44 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_tab_to_list(char **tab)
{
	t_list	*list;
	t_list	*node;
	int		y;

	y = 0;
	list = NULL;
	while (tab[y])
	{
		node = ft_lstnew(tab[y], sizeof(tab[y]));
		ft_lstadd_end(&list, node);
		y++;
	}
	return (list);
}
