/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:59 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:35:02 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlstsize(t_dlst *dlst)
{
	size_t	len;

	if (!dlst)
		return (0);
	len = 0;
	while (dlst && ++len)
		dlst = dlst->next;
	return (len);
}
