/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:50:54 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/26 19:42:18 by dalitt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_a(char **a, int i, int j)
{
	return (!ft_strncmp("<>", &a[i][j], 2)
			|| !ft_strncmp("><", &a[i][j], 2) || !ft_strncmp("<|", &a[i][j], 2)
			|| !ft_strncmp(">|", &a[i][j], 2) || !ft_strncmp("||", &a[i][j], 2)
			|| (a[i][j +2] && (!ft_strncmp(">>>", &a[i][j], 3) ||
			!ft_strncmp("<<<", &a[i][j], 3))));
}

int	check_piperr2(char **a)
{
	int	i;
	int	j;
	int	q[2];

	q[0] = 0;
	q[1] = 0;
	i = 0;
	if (!a[0])
		return (1);
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			q[0] = (q[0] + (!q[1] && a[i][j] == '\'')) % 2;
			q[1] = (q[1] + (!q[0] && a[i][j] == '\"')) % 2;
			if (!(q[0] || q[1]) && a[i][j +1] && check_a(a, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_piperr(char **a)
{
	int	i;

	if (!a[0])
		return (1);
	if (a[0][0] == '|')
		return (0);
	i = 0;
	while (a[i])
	{
		if (a[i][0] && (ft_strchr("<|>", a[i][ft_strlen(a[i]) - 1])
		&& a[i +1] && a[i +1][0] && ft_strchr("<|>", a[i +1][0])))
			return (0);
		i++;
	}
	if (ft_strchr("<|>", a[i -1][ft_strlen(a[i -1]) - 1]))
		return (0);
	return (1);
}

int	mini_exit(t_list *cmd, int *is_exit)
{
	t_mini	*node;
	long	status[2];

	node = cmd->content;
	*is_exit = !cmd->next;
	if (*is_exit)
		ft_putstr_fd("exit\n", 2);
	if (!node->full_cmd || !node->full_cmd[1])
		return (g_status);
	status[1] = ft_atoi2(node->full_cmd[1], &status[0]);
	if (status[1] == -1)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(node->full_cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (2);
	}
	else if (node->full_cmd[2])
	{
		*is_exit = 0;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	status[0] %= 256 + 256 * (status[0] < 0);
	return (status[0]);
}

void	cd_error(char **str[2])
{
	DIR		*dir;

	dir = NULL;
	if (str[0][1])
		dir = opendir(str[0][1]);
	if (!str[0][1] && str[1][0] && !str[1][0][0])
	{
		g_status = 1;
		ft_putstr_fd("minishell: HOME not set\n", 2);
	}
	if (str[1][0] && !str[0][1])
		g_status = chdir(str[1][0]) == -1;
	if (str[0][1] && dir && access(str[0][1], F_OK) != -1)
		chdir(str[0][1]);
	else if (str[0][1] && access(str[0][1], F_OK) == -1)
		mini_perror(NDIR, str[0][1], 1);
	else if (str[0][1])
		mini_perror(NOT_DIR, str[0][1], 1);
	if (str[0][1] && dir)
		closedir(dir);
}
