/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:08:58 by ale-batt          #+#    #+#             */
/*   Updated: 2016/08/30 13:54:31 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist		*ft_llstnew(const void *content)
{
	t_llist	*new;

	new = (t_llist*)malloc(sizeof(t_llist));
	if (new)
	{
		new->content = (void*)content;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}
