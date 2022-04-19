/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:27 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:34:29 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstlast(t_dlst *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->next)
		dlst = dlst->next;
	return (dlst);
}
