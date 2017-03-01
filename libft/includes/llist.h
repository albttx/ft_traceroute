/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:58:37 by world42           #+#    #+#             */
/*   Updated: 2016/08/30 14:01:16 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLIST_H
# define LLIST_H

typedef struct		s_llist
{
	void			*content;
	struct s_llist	*next;
	struct s_llist	*prev;
}					t_llist;

t_llist				*ft_llstnew(void const *content);
void				ft_llstadd(t_llist **alst, t_llist *new);
void				ft_llstadd_end(t_llist **alst, t_llist *new);
int					ft_llstlen(t_llist *lst);
t_llist				*ft_llstcpy(t_llist *list);
void				ft_llstfree(t_llist *lst);

#endif
