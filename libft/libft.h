/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:27:15 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:27:16 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef MAX_OPEN
#  define MAX_OPEN 1024
# endif

typedef struct s_dlst
{
	int				data;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}	t_dlst;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *nptr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(char c);
int					ft_isprint(int c);
int					ft_isspace(char c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				**ft_split(const char *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *src);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *str, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *newnode);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_dlstadd_back(t_dlst **dlst, t_dlst *new);
void				ft_dlstadd_front(t_dlst **dlst, t_dlst *new);
t_dlst				*ft_dlstfirst(t_dlst *dlst);
t_dlst				*ft_dlstlast(t_dlst *dlst);
t_dlst				*ft_dlstnew(int data);
int					ft_dlstsize(t_dlst *dlst);
char				*ft_get_next_line(int fd);

#endif
