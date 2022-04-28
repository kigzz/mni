/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:50:09 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/19 13:50:10 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_status;

static t_prompt	init_vars(t_prompt prompt, char *str, char **argv)
{
	char	*num;

	str = getcwd(NULL, 0);
	prompt.envp = mini_setenv("PWD", str, prompt.envp, 3);
	free(str);
	str = mini_getenv("SHLVL", prompt.envp, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.envp = mini_setenv("SHLVL", num, prompt.envp, 5);
	free(num);
	str = mini_getenv("PATH", prompt.envp, 4);
	if (!str)
		prompt.envp = mini_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", prompt.envp, 4);
	free(str);
	str = mini_getenv("_", prompt.envp, 1);
	if (!str)
		prompt.envp = mini_setenv("_", argv[0], prompt.envp, 1);
	free(str);
	return (prompt);
}

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt.cmds = NULL;
	prompt.envp = ft_matrix_dup(envp);
	g_status = 0;
	prompt = init_vars(prompt, str, argv);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	char				*output;
	t_prompt			prompt;

	if (argc != 1)
	{
		ft_putstr_fd("No arguments after ./minishell\n", 1);
		return (0);
	}
	prompt = init_prompt(argv, envp);
	while (argc && argv)
	{
		signal(SIGINT, handle_signal);
		signal(SIGPIPE, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		output = readline("minishell $> ");
		if (!check_args(output, &prompt))
			break ;
	}
	exit(g_status);
}
