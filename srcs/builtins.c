/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:50:33 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/19 13:50:33 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin2(t_prompt *prompt, t_list *cmd, int *is_exit, char **a)
{
	int	n;

	n = 0;
	if (a)
		n = ft_strlen(*a);
	if (a && !ft_strncmp(*a, "exit", n) && n == 4)
	{
		g_status = mini_exit(cmd, is_exit);
		ft_matrix_free(&prompt->envp);
	}
	else if (!cmd->next && a && !ft_strncmp(*a, "cd", n) && n == 2)
		g_status = mini_cd(prompt);
	else if (!cmd->next && a && !ft_strncmp(*a, "export", n) && n == 6)
		g_status = mini_export(prompt);
	else if (!cmd->next && a && !ft_strncmp(*a, "unset", n) && n == 5)
		g_status = mini_unset(prompt);
	else
		sig_and_exec(prompt, cmd);
}

int	builtin(t_prompt *prompt, t_list *cmd, int *is_exit)
{
	char	**a;

	while (cmd)
	{
		a = ((t_mini *)cmd->content)->full_cmd;
		builtin2(prompt, cmd, is_exit, a);
		if (!cmd->next && a)
			prompt->last_cmd = last_cmd(prompt, *a);
		cmd = cmd->next;
	}
	return (g_status);
}

int	mini_cd(t_prompt *p)
{
	char	**str[2];
	char	*aux;

	g_status = 0;
	str[0] = ((t_mini *)p->cmds->content)->full_cmd;
	aux = mini_getenv("HOME", p->envp, 4);
	if (!aux)
		aux = ft_strdup("");
	str[1] = ft_matrix_extend(NULL, aux);
	free(aux);
	aux = getcwd(NULL, 0);
	str[1] = ft_matrix_extend(str[1], aux);
	free(aux);
	cd_error(str);
	if (!g_status)
		p->envp = mini_setenv("OLDPWD", str[1][1], p->envp, 6);
	aux = getcwd(NULL, 0);
	if (!aux)
		aux = ft_strdup("");
	str[1] = ft_matrix_extend(str[1], aux);
	free(aux);
	p->envp = mini_setenv("PWD", str[1][2], p->envp, 3);
	ft_matrix_free(&str[1]);
	return (g_status);
}

int	mini_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
	{
		ft_putstr_fd("pwd: error retrieving current directory: ", 2);
		ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
		ft_putstr_fd("No such files or directory\n", 2);
	}
	ft_putendl_fd(buf, 1);
	free(buf);
	return (0);
}

int	mini_echo(t_list *cmd)
{
	int		newline;
	int		i[2];
	char	**argv;
	t_mini	*node;

	i[0] = 0;
	i[1] = 0;
	newline = 1;
	node = cmd->content;
	argv = node->full_cmd;
	while (argv && argv[++i[0]])
	{
		if (!i[1] && !mini_echo_check(argv[i[0]]))
			newline = 0;
		else
		{
			i[1] = 1;
			ft_putstr_fd(argv[i[0]], 1);
			if (argv[i[0] + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
