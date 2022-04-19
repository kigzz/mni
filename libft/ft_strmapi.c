/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:58:40 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:58:51 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (NULL);
	else
	{
		while (i < s_len)
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}
