/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:10 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:12 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		if (dest2[i] == (unsigned char)c)
			return ((void *)dest + i + 1);
		i++;
	}
	return (NULL);
}
