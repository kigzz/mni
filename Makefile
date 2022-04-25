
#SETUP

NAME			=	minishell
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -Iincludes -Ilibft -g3
#-fsanitize=address

RM				=	rm -rf

#LIB NAMES

LIBFT_NAME		=	libft.a
LIBFT_DIR		=	libft

#LIB FLAGS

LIBFT_FLAGS		=	-Llibft -lft

#FILES AND PATH

SRCS    		=	main.c handle_signal.c builtins.c builtins_utils.c env.c error.c execution.c expansion.c  \
					ft_cmd_split.c ft_cmd_trim.c ft_strtrim_all.c get_cmd.c get_parameters.c heredoc.c \
					parse_arguments.c fill_nodes.c
SRCS_DIR		=	srcs/
SRCS_PATH		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS    	=	$(SRCS_PATH:%.c=%.o)

# RULES

%.o : %.c
					$(CC) $(FLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_SRCS)
					make -C $(LIBFT_DIR)
					$(CC) $(FLAGS) $(OBJ_SRCS) $(LIBFT_FLAGS) -lreadline -o $(NAME)

clean:
					$(RM) $(OBJ_SRCS)
					$(RM) $(OBJ_SRCS_BONUS)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS)
					make fclean -C libft

re:					fclean all

.PHONY:				all clean fclean bonus re
