/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:24:54 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:24:59 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(long n, char *base, int fd)
{
	int	count;
	int	base_len;

	count = 0;
	if (!base || !base[0] || ft_strlen(base) < 2)
		base = "0123456789";
	base_len = ft_strlen(base);
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n >= base_len && n < 2147483648)
	{
		ft_putnbr_base_fd(n / base_len, base, fd);
		ft_putnbr_base_fd(n % base_len, base, fd);
	}
	else
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
