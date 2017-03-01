/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 19:29:11 by ale-batt          #+#    #+#             */
/*   Updated: 2016/08/31 16:23:14 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static void		ft_inverse(t_hash **a, t_hash **b)
{
	t_hash *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	(*b)->next = *a;
	(*a)->next = (*b)->next;
}

void			ft_sort_hash(t_hash **hash)
{
	t_hash *tmp;
	t_hash *first;

	first = *hash;
	tmp = *hash;
	tmp = first;
	while (tmp)
	{
		if (tmp->next && ft_strcmp(tmp->key, (tmp->next)->key) > 0)
		{
			ft_inverse(&tmp, &(tmp->next));
			tmp = first;
			continue ;
		}
		tmp = tmp->next;
	}
}
