/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:58:37 by world42           #+#    #+#             */
/*   Updated: 2016/11/05 22:16:44 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lst(void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_end(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				*ft_lstcmp(t_list *l, void *c, int (*f)(void*, void*));
void				ft_lstdelone(t_list **l, void (*d)(void*, size_t));
void				ft_lstfree(t_list *lst);
t_list				*ft_lstinsert(t_list **l, t_list *n,
		int (*f)(void*, void*));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				ft_lstlen(t_list *lst);
void				ft_lstsort(t_list **list, int (*cmp)(void *, void *));

#endif
