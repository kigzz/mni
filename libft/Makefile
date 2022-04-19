# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 20:27:21 by bpouchep          #+#    #+#              #
#    Updated: 2020/07/15 20:27:23 by bpouchep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_atoi.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c \
				ft_split.c ft_strdup.c \
				ft_strcat.c	ft_strlcat.c \
				ft_strcpy.c	ft_strlcpy.c \
				ft_strlen.c	ft_strncmp.c \
				ft_tolower.c ft_toupper.c \
				ft_memset.c ft_memcpy.c \
				ft_memccpy.c ft_strchr.c \
				ft_strnstr.c ft_strrchr.c \
				ft_memmove.c ft_bzero.c \
				ft_memcmp.c ft_memchr.c \
				ft_calloc.c ft_substr.c \
				ft_strjoin.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_strtrim.c \
				ft_strmapi.c ft_itoa.c \
				ft_lstnew.c ft_lstadd_front.c \
				ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c ft_dlstadd_front.c \
				ft_dlstadd_back.c ft_dlstfirst.c \
				ft_dlstlast.c ft_dlstnew.c \
				ft_dlstsize.c get_next_line.c \
				ft_atoi2.c ft_lst_to_matrix.c \
				ft_matrix_dup.c ft_matrix_extend.c \
				ft_matrix_free.c ft_matrixlen.c \
				ft_putmatrix_fd.c ft_replace_in_matrix.c \
				ft_strchr_char.c ft_strchr_set.c \
				ft_isspace.c

OBJS		=	$(SRCS:.c=.o)

CC          =	gcc

RM			=   rm -rf

CFLAGS		=   -Wall -Wextra -Werror

LIB         =   ar rc $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
				$(LIB) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
