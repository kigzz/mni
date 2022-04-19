/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:33:59 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:34:02 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstfirst(t_dlst *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->prev)
		dlst = dlst->prev;
	return (dlst);
}
