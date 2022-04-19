/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:20 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:22 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	while (n > 0)
	{
		if (*str2 == (unsigned char)c)
			return ((void *)&*str2);
		str2++;
		n--;
	}
	return (NULL);
}
