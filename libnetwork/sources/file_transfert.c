/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transfert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:48:18 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/20 17:12:46 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define ERR_AUTH -1
#define ERR_FILE_TRANSFERT -2

static int		is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

static int		send_bytes(int sock, size_t len, uint32_t byte)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (sock_send_uint32(sock, byte) == -1)
		{
			sock_send_uint32(sock, -1);
			puts("send_bytes ERROR");
			return (ERR_FILE_TRANSFERT);
		}
		i++;
	}
	return (1);
}

int				sock_send_file(const int sock, const char *file)
{
	uint32_t	byte;
	size_t		ret;
	int			fd;

	ret = 1;
	fd = -1;
	if (is_directory(file) == 0)
		fd = open(file, O_RDONLY);
	if (fd <= 0)
		ret = 0;
	sock_send_uint32(sock, (fd > 0) ? 1 : 0);
	byte = sock_get_uint32(sock);
	if (ret == 0 || byte == 0)
		return (ERR_AUTH);
	while (ret > 0)
	{
		byte = 0;
		if ((ret = read(fd, &byte, 1)) <= 0)
			break ;
		if (send_bytes(sock, ret, byte) == -1)
			return (ERR_FILE_TRANSFERT);
	}
	sock_send_uint32(sock, -1);
	close(fd);
	return (1);
}

int				sock_recv_file(const int sock, char *filename)
{
	int			fd;
	uint32_t	byte;
	int			ret;

	ret = 1;
	fd = 0;
	byte = sock_get_uint32(sock);
	if (byte == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0644);
	if (fd <= 0)
		ret = -1;
	sock_send_uint32(sock, (fd > 0) ? 1 : 0);
	if (byte == 0 || ret == -1)
		return (ERR_AUTH);
	while (ret == 1)
	{
		byte = sock_get_uint32(sock);
		if (byte == (uint32_t)-1)
			break ;
		write(fd, &byte, 1);
	}
	close(fd);
	return (ret);
}
