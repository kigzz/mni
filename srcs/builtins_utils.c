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
