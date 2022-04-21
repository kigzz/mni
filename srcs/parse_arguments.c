/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:53:54 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/19 13:53:54 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**split_all(char **args, t_prompt *prompt)
{
	char	**subsplit;
	int		i;
	int		quotes[2];

	i = -1;
	while (args && args[++i])
	{
		args[i] = expand_vars(args[i], -1, quotes, prompt);
		args[i] = expand_path(args[i], -1, quotes, \
			mini_getenv("HOME", prompt->envp, 4));
		subsplit = ft_cmd_split(args[i], "<|>");
		ft_replace_in_matrix(&args, subsplit, i);
		i += ft_matrixlen(subsplit) - 1;
		ft_matrix_free(&subsplit);
	}
//	printf ("---- FT_CMD_SPLIT ----\n");
//	for (i = 0; i < ft_matrixlen(args); i++)
//		printf("%s\n", args[i]);
//	printf ("----------------------\n");
	return (args);
}

static void	*parse_args(char **args, t_prompt *p)
{
	int	is_exit;
	int	i;

	is_exit = 0;
	p->cmds = fill_nodes(split_all(args, p), -1);
	if (!p->cmds)
		return (p);
	i = ft_lstsize(p->cmds);
	g_status = builtin(p, p->cmds, &is_exit, 0);
	while (i-- > 0)
		waitpid(-1, &g_status, 0);
	if (!is_exit && g_status == 13)
		g_status = 0;
	if (g_status > 255)
		g_status = g_status / 255;
	if (args && is_exit)
	{
		ft_lstclear(&p->cmds, free_content);
		return (NULL);
	}
	return (p);
}

void	*check_args(char *out, t_prompt *p)
{
	char	**a;
	t_mini	*n;

	if (!out)
	{
		ft_putstr_fd("exit\n", 1);
		ft_matrix_free(&p->envp);
		return (NULL);
	}
	if (out[0] != '\0')
		add_history(out);
	ft_replace_tabs_returns(out);
	a = ft_cmd_trim(out, " ");
//	printf("---------- CMD_TRIM --------\n");
//	for (int i = 0; i < ft_matrixlen(a); i++)
//		printf("%s\n", a[i]);
//	printf("----------------------------\n");
	free(out);
	if (!a)
		mini_perror(QUOTE, NULL, 1);
	if (!a)
		return ("");
	p = parse_args(a, p);
	if (p && p->cmds)
		n = p->cmds->content;
//	printf ("------- t_mini ------\n");
//	for (int i = 0; i < ft_matrixlen(n->full_cmd); i++)
//		printf("full cmd %s\n", n->full_cmd[i]);
//	printf("full path %s\n", n->full_path);
//	printf("infile %d\n", n->infile);
//	printf("outfile %d\n", n->outfile);
//	printf ("----------------------\n");
	if (p && p->cmds && n && n->full_cmd && ft_lstsize(p->cmds) == 1)
		p->envp = mini_setenv("_", n->full_cmd[ft_matrixlen(n->full_cmd) - 1], \
			p->envp, 1);
	if (p && p->cmds)
		ft_lstclear(&p->cmds, free_content);
	return (p);
}
