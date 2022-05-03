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

void	handle_status(t_prompt *p, int is_exit, int i)
{
	i = ft_lstsize(p->cmds);
	if (i > 1 && !is_exit && (g_status == 13 || g_status == 0
			|| g_status == 131 || g_status == 2))
	{
		if (p->last_cmd == 1)
			g_status = 0;
		else
			g_status = 127;
	}
	else if (!is_exit && g_status == 2)
		g_status = 130;
	p->last_cmd = 0;
	p->is_heredoc = 0;
}

void	free_content(void *content)
{
	t_mini	*node;

	node = content;
	ft_matrix_free(&node->full_cmd);
	free(node->full_path);
	if (node->infile != STDIN_FILENO && node->infile != -1)
		close(node->infile);
	if (node->outfile != STDOUT_FILENO && node->outfile != -1)
		close(node->outfile);
	free(node);
}

void	*mini_perror(int err_type, char *param, int err)
{
	g_status = err;
	if (err_type == QUOTE)
		ft_putstr_fd("minishell: error while looking for matching quote\n", 2);
	else if (err_type == NDIR)
		ft_putstr_fd("minishell: No such file or directory: ", 2);
	else if (err_type == NPERM)
		ft_putstr_fd("minishell: permission denied: ", 2);
	else if (err_type == NCMD)
		ft_putstr_fd("minishell: command not found: ", 2);
	else if (err_type == DUPERR)
		ft_putstr_fd("minishell: dup2 failed\n", 2);
	else if (err_type == FORKERR)
		ft_putstr_fd("minishell: fork failed\n", 2);
	else if (err_type == PIPERR)
		ft_putstr_fd("minishell: error creating pipe\n", 2);
	else if (err_type == PIPENDERR)
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	else if (err_type == IS_DIR)
		ft_putstr_fd("minishell: Is a directory: ", 2);
	else if (err_type == NOT_DIR)
		ft_putstr_fd("minishell: Not a directory: ", 2);
	ft_putendl_fd(param, 2);
	return (NULL);
}
