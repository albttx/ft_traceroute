/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:36:50 by ale-batt          #+#    #+#             */
/*   Updated: 2016/12/21 17:08:18 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOG_H
# define FT_LOG_H

# include <fcntl.h>
# include "libft.h"

# define TMPLOG "/tmp/logs.txt"
# define CLOSE "CLOSE"

# define LOCK_DEFAULT_FD 1

# define LOCK 1
# define UNLOCK -1

typedef enum	e_flags {
	FLAG_ENABLE = 1,
	FLAG_TIME = 2,
}				t_flags;

typedef struct	s_log
{
	int			fd;
	t_flags		flags;
}				t_log;

t_log			*log_singleton(char *path);
void			log_init(char *logfile);
void			log_done(void);
int				log_getfd(void);

void			log_print(char *msg, ...);
void			log_println(char *msg, ...);
void			log_error(char *str, ...);
void			log_fatal(char *msg, ...);

#endif
