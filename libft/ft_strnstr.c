/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:26:24 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:26:30 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = -1;
		while (haystack[++i] && haystack[i] == needle[i] && len - i)
			if (!needle[i + 1])
				return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
