/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:38:26 by ale-batt          #+#    #+#             */
/*   Updated: 2016/08/30 13:50:51 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist	*ft_llstcpy(t_llist *list)
{
	t_llist	*new;
	t_llist	*tmp;

	new = NULL;
	tmp = list;
	while (tmp)
	{
		ft_llstadd_end(&new, ft_llstnew(tmp->content));
		tmp = tmp->next;
	}
	return (new);
}
