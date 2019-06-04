/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:51:44 by xinzhang          #+#    #+#             */
/*   Updated: 2019/05/27 08:57:47 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

int				ft_isspace(char c);

int				ft_tolower(int c);

int				ft_toupper(int c);

int				ft_atoi(const char *str);

char			*ft_itoa(int n);

void			ft_putendl(const char *s);

void			ft_putendl_fd(const char *s, int fd);

void			ft_putchar(char c);

void			ft_putchar_fd(char c, int fd);

void			ft_putnbr(int n);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr(const char *s);

void			ft_putstr_fd(const char *s, int fd);

void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *s1, const void *s2, size_t n);

void			*ft_memmove(void *s1, const void *s2, size_t n);

void			*ft_memset(void *s, int c, size_t n);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strchr(const char *s, int c);

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcpy(char *s1, const char *s2);

char			*ft_strdup(const char *s);

size_t			ft_strlen(const char *s);

char			*ft_strncat(char *s1, const char *s2, size_t n);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strncpy(char *s1, const char *s2, size_t n);

char			*ft_strndup(const char *s, size_t size);

char			*ft_strrchr(const char *s, int c);

char			*ft_strstr(const char *s1, const char *s2);

void			ft_bzero(void *s, size_t n);

size_t			ft_strlcat(char *s1, const char *s2, size_t n);

char			*ft_strnstr(const char *s1, const char *s2, size_t n);

void			*ft_memalloc(size_t size);

void			ft_memdel(void **ap);

void			ft_strclr(char *s);

void			ft_strdel(char **as);

int				ft_strequ(const char *s1, const char *s2);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmap(const char *s, char (*f)(char));

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

int				ft_strnequ(const char *s1, const char *s2, size_t n);

char			*ft_strnew(size_t size);

char			**ft_strsplit(const char *s, char c);

char			*ft_strsub(const char *s, unsigned int start, size_t len);

char			*ft_strtrim(const char *s);
/*
** get next line:
*/
int				ft_search(char *a);

char			*ft_strnrenew(char *a, char *b, int len);

char			*ft_strrenew(char *a, char *b);

void			ft_add_to_tail(char *b, int tc, t_list **t);

t_list			*ft_append(t_list *t, char *n);

t_list			*ft_get_last(t_list *t);

char			*ft_strnjoin(char *a, char *b, int n);

char			*ft_strjoin(char *a, char *b);
#endif
