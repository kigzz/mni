/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:26:11 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:26:13 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	int		size_find;

	if (!str || !to_find)
		return (NULL);
	i = 0;
	size_find = 0;
	while (to_find[size_find] != '\0')
		size_find++;
	if (size_find == 0)
		return ((char *)str);
	while (str[i] != '\0' && n > i)
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j] && n > i + j)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		else
			i++;
	}
	return (0);
}
