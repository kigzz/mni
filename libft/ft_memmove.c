/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:52 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:54 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src2 < dest2)
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*dest2++ = *src2++;
			n--;
		}
	}
	return ((void *)dst);
}
