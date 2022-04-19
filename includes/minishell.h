

#ifndef MINISHELL2_MINISHELL_H
#define MINISHELL2_MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/ioctl.h>


void	handle_sigint(int sig);



#endif //MINISHELL2_MINISHELL_H
