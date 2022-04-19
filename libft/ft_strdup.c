/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:24:55 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:24:56 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*d;
	size_t	size;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	d = (char *)malloc(size + 1);
	if (!d)
		return (NULL);
	ft_strlcpy(d, src, size + 1);
	return (d);
}
