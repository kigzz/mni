/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 05:06:37 by bpouchep          #+#    #+#             */
/*   Updated: 2022/05/02 05:06:39 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*check_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	if (!path || !*path)
		return (NULL);
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

int	last_cmd(t_prompt *prompt, char *args)
{
	char	*path;
	char	**s;
	char	*last_cmd;

	path = mini_getenv("PATH", prompt->envp, 4);
	s = ft_split(path, ':');
	last_cmd = check_cmd(s, args);
	ft_matrix_free(&s);
	free(path);
	if (!last_cmd)
	{
		free(last_cmd);
		return (0);
	}
	free(last_cmd);
	return (1);
}
