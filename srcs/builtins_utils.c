/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:17:25 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/25 19:17:26 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	mini_echo_check(char *str)
{
	int	i;

	if (str && !ft_strncmp(str, "-n", 2))
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != 'n')
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

int	mini_export_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '=' || ft_isdigit(str[i]))
	{
		printf("minishell: export: `%s': not a valid identifier\n", str);
		return (1);
	}
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0)
		{
			printf("minishell: export: `%s': not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	mini_unset_check(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
	{
		printf("minishell: unset: `%s': not a valid identifier\n", str);
		return (1);
	}
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
		{
			printf("minishell: unset: `%s': not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_builtin(t_mini *n)
{
	int		l;

	if (!n->full_cmd)
		return (0);
	if ((n->full_cmd && ft_strchr(*n->full_cmd, '/')) || (n->full_path && \
		ft_strchr(n->full_path, '/')))
		return (0);
	l = ft_strlen(*n->full_cmd);
	if (!ft_strncmp(*n->full_cmd, "pwd", l) && l == 3)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "env", l) && l == 3)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "cd", l) && l == 2)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "export", l) && l == 6)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "unset", l) && l == 5)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "echo", l) && l == 4)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "exit", l) && l == 4)
		return (1);
	return (0);
}
