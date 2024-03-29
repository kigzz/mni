/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:50:15 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/19 13:50:16 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
//		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
//		rl_redisplay();
	}
}

void	handle_sigint_exec(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (sig == SIGQUIT)
	{
		g_status = 131;
		ft_putstr_fd("Quit (core dumped)\n", 1);
	}
}

void	handle_signal_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	sig_and_exec(t_prompt *prompt, t_list *cmd)
{
	signal(SIGINT, handle_sigint_exec);
	signal(SIGQUIT, handle_sigint_exec);
	exec_cmd(prompt, cmd);
}
