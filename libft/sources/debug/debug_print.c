/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:20:10 by ale-batt          #+#    #+#             */
/*   Updated: 2016/01/25 21:07:56 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	open debug.txt with tail -f
*/

void	set_debug_mode(int mode)
{
	if (mode == ON)
		g_dbg = fopen("debug.txt", "a+");
	else
		fclose(g_dbg);
}

void	dbg_print(char *format)
{
	FILE *fp;

	fp = fopen("debug.txt", "a+");
	fprintf(fp, "%s", format);
	fclose(fp);
}
