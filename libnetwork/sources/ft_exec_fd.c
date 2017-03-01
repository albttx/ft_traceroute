/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:30:40 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 15:54:33 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libnetwork.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void	exec_in_fd(const char *bname, char **argv, const int fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		if (fd != 1 && fd != 2)
		{
			dup2(fd, 1);
			dup2(fd, 2);
		}
		execv(bname, argv);
		exit(EXIT_FAILURE);
	}
	wait4(pid, &status, 0, 0);
	if (fd != 1 && fd != 2)
		sock_send_eot(fd);
}
