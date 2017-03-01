/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:53:38 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/31 15:30:01 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# include "libft.h"

typedef struct		s_hash
{
	void			*key;
	void			*value;
	struct s_hash	*next;
	struct s_hash	*first;

}					t_hash;

void				ft_add_hash(t_hash **hash, void *key, void *value);
void				ft_read_hash(t_hash *hash);
void				ft_free_hash(t_hash **hash);
int					ft_len_hash(t_hash *hash);

void				*ft_get_value_hash(t_hash *hash, void *key);
void				*ft_get_key_hash(t_hash *hash, void *value);
void				ft_remove_key_hash(t_hash **hash, void *key);

void				ft_modify_value(t_hash *hash, void *key, void *newvalue);
void				ft_sort_hash(t_hash **hash);

#endif
