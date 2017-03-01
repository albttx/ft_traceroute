/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 20:57:27 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/31 15:53:34 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static t_hash	*ft_set_value(void *key, void *value)
{
	t_hash	*new;

	new = (t_hash *)malloc(sizeof(t_hash));
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

void			ft_add_hash(t_hash **hash, void *key, void *value)
{
	t_hash	*new;
	t_hash	*tmp;

	new = ft_set_value(key, value);
	if (*hash == NULL)
		*hash = new;
	else
	{
		tmp = *hash;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
