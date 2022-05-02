cmake_minimum_required(VERSION 3.21)
project(minishell2 C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell2 srcs/main.c srcs/handle_signal.c includes/minishell.h srcs/builtins.c srcs/env.c srcs/error.c
        srcs/execution.c srcs/expansion.c srcs/fill_nodes.c srcs/get_cmd.c srcs/ft_cmd_split.c srcs/ft_cmd_trim.c
        srcs/ft_strtrim_all.c srcs/parse_arguments.c srcs/get_parameters.c srcs/heredoc.c
        libft/libft.h
        srcs/builtins_utils.c srcs/error2.c srcs/last_cmd.c)

