/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:26:30 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:26:34 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			j = i;
			k = 1;
		}
		i++;
	}
	if (j >= 0 && k == 1)
		return ((char *)&str[j]);
	else if ((char)c == '\0')
		return ((char *)&str[i]);
	else
		return (0);
}
