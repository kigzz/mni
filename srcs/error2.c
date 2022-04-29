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
