#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	char	*output;
	(void)argv;

	if (argc == 1)
	{
		while (42)
		{
			signal(SIGINT, handle_sigint);
			signal(SIGQUIT, SIG_IGN);
			output = readline(">$ ");
			if (!output)
			{
				ft_putstr_fd("exit\n", 1);
				return (0);
			}
			if (output[0] != '\0')
				add_history(output);
			printf("output = %s\n", output);
			// Parser les arguments
		}
	}
	else
		return (0);
}
