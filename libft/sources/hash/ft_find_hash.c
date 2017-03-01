/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 20:57:52 by ale-batt          #+#    #+#             */
/*   Updated: 2016/11/02 15:10:48 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	*ft_get_value_hash(t_hash *hash, void *key)
{
	t_hash	*tmp;

	tmp = hash;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	*ft_get_key_hash(t_hash *hash, void *value)
{
	t_hash	*tmp;

	tmp = hash;
	while (tmp)
	{
		if (ft_strcmp(tmp->value, value) == 0)
			return (tmp->key);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_remove_key_hash(t_hash **hash, void *key)
{
	t_hash	*tmp;
	t_hash	*prev;

	tmp = *hash;
	prev = tmp;
	while (tmp)
	{
		if (ft_strequ(tmp->key, key))
		{
			prev->next = tmp->next;
			if (tmp == prev)
				*hash = tmp->next;
			free(tmp);
			tmp = prev->next;
			continue ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
