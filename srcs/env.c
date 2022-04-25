/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:50:46 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/19 13:50:47 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*mini_getenv(char *var, char **envp, int n)
{
	int	i;
	int	n2;

	i = 0;
	if (n < 0)
		n = ft_strlen(var);
	while (!ft_strchr(var, '=') && envp && envp[i])
	{
		n2 = n;
		if (n2 < ft_strchr_char(envp[i], '='))
			n2 = ft_strchr_char(envp[i], '=');
		if (!ft_strncmp(envp[i], var, n2))
			return (ft_substr(envp[i], n2 + 1, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}

char	**mini_setenv(char *var, char *value, char **envp, int n)
{
	int		i[2];
	char	*aux[2];

	if (n < 0)
		n = ft_strlen(var);
	i[0] = -1;
	aux[0] = ft_strjoin(var, "=");
	aux[1] = ft_strjoin(aux[0], value);
	free(aux[0]);
	while (!ft_strchr(var, '=') && envp && envp[++i[0]])
	{
		i[1] = n;
		if (i[1] < ft_strchr_char(envp[i[0]], '='))
			i[1] = ft_strchr_char(envp[i[0]], '=');
		if (!ft_strncmp(envp[i[0]], var, i[1]))
		{
			aux[0] = envp[i[0]];
			envp[i[0]] = aux[1];
			free(aux[0]);
			return (envp);
		}
	}
	envp = ft_matrix_extend(envp, aux[1]);
	free(aux[1]);
	return (envp);
}

static int	var_in_envp(char *argv, char **envp, int i[2])
{
	int	pos;

	i[1] = 0;
	pos = ft_strchr_char(argv, '=');
	if (pos == -1)
		return (-1);
	while (envp[i[1]])
	{
		if (!ft_strncmp(envp[i[1]], argv, pos + 1))
			return (1);
		i[1]++;
	}
	return (0);
}

int	mini_export(t_prompt *prompt)
{
	int		i[2];
	int		pos;
	char	**argv;

	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	for (int j = 0; j < ft_matrixlen(argv); j++)
		printf("argv[%d] = %s\n", j, argv[j]);
	if (ft_matrixlen(argv) >= 2)
	{
		i[0] = 1;
		while (argv[i[0]])
		{
			pos = var_in_envp(argv[i[0]], prompt->envp, i);
			if (pos == 1)
			{
				free(prompt->envp[i[1]]);
				prompt->envp[i[1]] = ft_strdup(argv[i[0]]);
			}
			else if (!pos)
				prompt->envp = ft_matrix_extend(prompt->envp, argv[i[0]]);
			i[0]++;
		}
	}
	return (0);
}

int	mini_unset(t_prompt *prompt)
{
	char	**argv;
	char	*aux;
	int		i[2];

	i[0] = 0;
	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(argv) >= 2)
	{
		while (argv[++i[0]])
		{
			if (argv[i[0]][ft_strlen(argv[i[0]]) - 1] != '=')
			{
				aux = ft_strjoin(argv[i[0]], "=");
				free(argv[i[0]]);
				argv[i[0]] = aux;
			}
			if (var_in_envp(argv[i[0]], prompt->envp, i))
				ft_replace_in_matrix(&prompt->envp, NULL, i[1]);
		}
	}
	return (0);
}
