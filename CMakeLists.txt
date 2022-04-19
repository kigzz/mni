cmake_minimum_required(VERSION 3.21)
project(minishell2 C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell2 srcs/main.c srcs/handle_sigint.c includes/minishell.h srcs/builtins.c srcs/env.c srcs/error.c
        srcs/execution.c srcs/expansion.c srcs/fill_nodes.c srcs/get_cmd.c srcs/ft_cmd_split.c srcs/ft_cmd_trim.c
        srcs/ft_strtrim_all.c srcs/parse_arguments.c srcs/get_parameters.c srcs/heredoc.c
        libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_dlstadd_back.c libft/ft_dlstadd_front.c
        libft/ft_dlstfirst.c libft/ft_dlstlast.c libft/ft_dlstnew.c libft/ft_dlstsize.c libft/ft_isalnum.c
        libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_front.c
        libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c
        libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c
        libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c  libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strcpy.c
        libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c
        libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_toupper.c libft/ft_tolower.c
        libft/get_next_line.c libft/libft.h libft/ft_isspace.c libft/ft_atoi2.c libft/ft_matrixlen.c
        libft/ft_matrix_extend.c libft/ft_matrix_dup.c libft/ft_matrix_free.c libft/ft_putmatrix_fd.c libft/ft_replace_in_matrix.c
        libft/ft_strchr_char.c libft/ft_strchr_set.c libft/ft_strrchr.c)

