/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:53:59 by world42           #+#    #+#             */
/*   Updated: 2016/08/26 14:46:32 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_H
# define CTYPE_H

# define ISLOWER(c)			(c >= 'a' && c <= 'z')
# define ISUPPER(c) 		(c >= 'A' && c <= 'Z')
# define ISDIGIT(c) 		(c >= '0' && c <= '9')
# define ISALPHA(c) 		(ISLOWER(c) || ISUPPER(c))
# define SPECIAL_SPACE 		(c == '\v' || c == '\f' || c == '\r')

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
