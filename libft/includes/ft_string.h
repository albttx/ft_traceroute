/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:58:37 by world42           #+#    #+#             */
/*   Updated: 2017/01/03 16:09:26 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# define STRINGIFY(x) #x

char		*ft_strajax(char *str);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *s1, const char *s2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strfdup(char *s1);
int			ft_strequ(const char *s1, const char *s2);
char		*ft_strgetnext(char ***str);
void		ft_striter(char *s, void (*f)(char*));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin_char(const char *s1, char c, const char *s2);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strfjoin(char *s1, char *s2);
char		*ft_strfljoin(char *s1, char *s2);
char		*ft_strfrjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
size_t		ft_strnlen(const char *s, size_t maxlen);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(const char *s, char c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
char		*ft_strtrim(const char *s);
char		*ft_substr(const char *src, size_t pos, size_t n);
char		*ft_ultijoin(char *str, ...);
int			ft_strempty(char *str);
char		*ft_strpreci(char *str, char c, int preci);

#endif
