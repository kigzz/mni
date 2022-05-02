/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:48:50 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/29 17:48:52 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_fd_error(char *path, const int *flags)
{
	if (!flags[0] && access(path, F_OK) == -1)
		mini_perror(NDIR, path, 127);
	else if (!flags[0] && access(path, R_OK) == -1)
		mini_perror(NPERM, path, 126);
	else if (flags[0] && access(path, W_OK) == -1
		&& access(path, F_OK) == 0)
		mini_perror(NPERM, path, 126);
}

void	err_cmd(t_prompt *prompt, const t_mini *n)
{
	if (!n->full_path || !n->full_cmd[0] || !n->full_cmd[0][0])
	{
		mini_perror(NCMD, *n->full_cmd, 127);
		prompt->error = 1;
	}
}

void	handle_status(t_prompt *p, int is_exit, int i, int status)
{
	i = ft_lstsize(p->cmds);
	if (i > 1 && !is_exit && (g_status == 13 || g_status == 0 || g_status == 131 || g_status == 2))// SIGPIPE IGNORE
	{
		if (p->last_cmd == 1)
			g_status = 0;
		else
			g_status = 127;
	}
	else if (!is_exit && g_status == 2)				// cat + ctrl c
		g_status = 130;
	else if (p->is_heredoc == 1)
	{
			if (status == -1)
				g_status = 0;
			else if (status == 130)
				g_status = 130;
	}
	p->last_cmd = 0;
	p->is_heredoc = 0;
}
