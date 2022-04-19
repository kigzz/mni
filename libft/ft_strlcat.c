/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:25:26 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:25:27 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	i = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size <= dest_size || size == 0)
		src_size = src_size + size;
	else
		src_size = src_size + dest_size;
	while (src[i] != '\0' && dest_size + 1 < size)
	{
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (src_size);
}
