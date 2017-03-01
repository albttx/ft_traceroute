/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnetwork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:53:57 by ale-batt          #+#    #+#             */
/*   Updated: 2017/02/21 11:09:03 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNETWORK_H
# define LIBNETWORK_H

# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define LOCALHOST "127.0.0.1"
# define LOCALHOST6 "::1"

# define EOT 4

# define IPV6 6
# define IPV4 4

# define MAX_LEN_IPV4 15
# define MAX_LEN_IPV6 39

# define BUFFSIZE 512

# define NOT_FOUND "ft_p: Command not found."

# define SIZED_PROTOCOL 1
# define LOOOP_PROTOCOL 2

int				create_tcp_server(int port, int ipv_protocol);
int				create_tcp_client(char *addr, int port);
int				accept_binder(int sock);

int				get_ipvx(const char *addr);
char			*ipv4_to_ipv6(const char *ipv4_addr);

int				sock_get_protocol(const int sock);
int				sock_announce_protocol(const int sock, const int protocol);

char			*sock_recv(const int sock);
int				sock_send(const int sock, uint32_t size, const char *msg);
void			sock_read(const int sock);
int				sock_send_eot(const int sock);

uint32_t		sock_get_uint32(const int sock);
int				sock_send_uint32(const int sock, const uint32_t nb);

int				sock_send_file(const int sock, const char *file);
int				sock_recv_file(const int sock, char *filename);

void			exec_in_fd(const char *bname, char **argv, const int fd);

char			*hostname_to_ip(const char *hostname);

#endif
