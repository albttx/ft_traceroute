/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:59:30 by world42           #+#    #+#             */
/*   Updated: 2017/02/20 16:36:12 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTS_H
# define PUTS_H

# include "libft.h"

# define DEFAULT   "\033[0m"
# define HIGHLIGHT "\033[1m"
# define UNDERLINE "\033[4m"
# define BLINK     "\033[5m"
# define BLACK     "\033[30m"
# define RED       "\033[31m"
# define GREEN     "\033[32m"
# define YELLOW    "\033[33m"
# define BLUE      "\033[34m"
# define PURPLE    "\033[35m"
# define CYAN      "\033[36m"
# define WHITE     "\033[37m"

# define TIME_YMD "%Y-%m-%d"
# define TIME_HMS "%H:%M:%S"
# define TIME_MS "%M:%S"
# define TIME_HM "%H:%M"
# define TIME_MDHMS "%m-%d %H:%M:%S"
# define TIME_MD "%m-%d"
# define TIME_YMDHMS "%Y-%m-%d %H:%M:%S"

void	ft_putbase(long l, int base, char *letters);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putdouble(double d, double epsilone);
void	ft_putstr_color(char *str, char *color);
void	ft_putendl_color(char *str, char *color);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putendl(const char *s);
void	ft_putfloat(float d, double epsilone);
void	ft_puthex_64(uint64_t l);
void	ft_puthex(unsigned long l);
void	ft_putlong(long l);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned long long nb);
void	ft_putpointer(void *p);
void	ft_putendl_color(char *str, char *color);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putstr(const char *s);
void	ft_putnull(char *s);

void	ft_multiputs_args(int fd, char *str, va_list *ap);
void	ft_multiputs(char *str, ...);
void	ft_multiputs_fd(int fd, char *str, ...);

void	ft_printtime(char *format);
void	ft_printtime_fd(char *format, int fd);

#endif
