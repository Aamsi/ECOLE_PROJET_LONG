/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:52:49 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:24:59 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(char *s);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
char			*ft_strdup(char *s);
int				ft_atoi(char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, void *src, int c, size_t n);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
void			*ft_memcpy(void *dest, void *src, size_t n);
void			*ft_memmove(void *dest, void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, size_t size);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strnstr(char *big, char *little, size_t len);
char			*ft_strrchr(char *s, int c);
char			*ft_strtrim(char *s1, char *set);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
size_t			ft_strlen_matrix(char **s);

#endif
