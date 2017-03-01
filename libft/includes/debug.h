/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:49:06 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:36:08 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define ON 1
# define OFF 0

# define DGB(mode) set_debug_mode(mode);

FILE	*g_dbg;

void	set_debug_mode(int mode);
void	dbg_print(char *str);

#endif
