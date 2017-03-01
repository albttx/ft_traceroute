/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:58:54 by world42           #+#    #+#             */
/*   Updated: 2017/02/07 16:51:05 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

char		**ft_tabcpy(char **src);
char		*ft_tabjoin(char **tab);
void		ft_tabdel(char ***tab);
int			ft_tablen(char **tab);
void		ft_freetab(char **tab);

#endif
