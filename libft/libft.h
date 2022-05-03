/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:32:15 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:32:21 by bpouchep         ###   ########.fr       */
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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
int			ft_atoi2(const char *nptr, long *nbr);
char		*ft_itoa(int n);
int			ft_putchar_fd(char c, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putnbr_base_fd(long n, char *base, int fd);
int			ft_putstr_fd(char *s, int fd);
char		**ft_split(const char *s, char c);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
int			ft_strchr_char(const char *s, int c);
int			ft_strchr_set(const char *s, char *set);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_nbrlen(long n, int base);
int			ft_isspace(char c);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_matrix_free(char ***m);
char		**ft_matrix_dup(char **m);
int			ft_putmatrix_fd(char **m, int nl, int fd);
int			ft_matrixlen(char **m);
char		**ft_matrix_extend(char **in, char *newstr);
char		**ft_matrix_replace_in(char ***big, char **small, int n);

#endif
