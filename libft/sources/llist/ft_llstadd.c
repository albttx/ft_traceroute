/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:21:05 by ale-batt          #+#    #+#             */
/*   Updated: 2016/08/30 13:48:32 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llstadd(t_llist **alst, t_llist *new)
{
	if (alst && new)
	{
		new->next = *alst;
		new->prev = NULL;
		*alst = new;
	}
}
