/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:51:33 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/19 13:51:34 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_substr_var(char *str, int i, t_prompt *prompt)
{
	char	*aux;
	int		pos;
	char	*path;
	char	*var;

	pos = ft_strchr_set(&str[i], "|\"\'$?>< /=") + (ft_strchr("$?", str[i]) != 0);
	if (pos == -1)
		pos = ft_strlen(str) - 1;
	aux = ft_substr(str, 0, i - 1);
	var = mini_getenv(&str[i], prompt->envp,
			ft_strchr_set(&str[i], "\"\'$|></= "));
	if (!var && str[i] == '?')
		var = ft_itoa(g_status);
	path = ft_strjoin(aux, var);
	free(aux);
	if ((i + pos) <= (int)(ft_strlen(str)))
		aux = ft_strjoin(path, &str[i + pos]);
	else
		aux = ft_strjoin(path, "\0");
	free(var);
	free(path);
	free(str);
	return (aux);
}

char	*expand_vars(char *str, int i, int quotes[2], t_prompt *prompt)
{
	quotes[0] = 0;
	quotes[1] = 0;
	while (str && str[++i])
	{
		quotes[0] = (quotes[0] + (!quotes[1] && str[i] == '\'')) % 2;
		quotes[1] = (quotes[1] + (!quotes[0] && str[i] == '\"')) % 2;
		if (!quotes[0] && str[i] == '$' && str[i + 1] && \
			((ft_strchr_set(&str[i + 1], "/~%^{}:; ") && !quotes[1]) || \
			(ft_strchr_set(&str[i + 1], "/~%^{}:;\"") && quotes[1])))
			return (expand_vars(get_substr_var(str, ++i, prompt), -1, \
				quotes, prompt));
	}
	return (str);
}
