/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:31:51 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:32:10 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlst **dlst, t_dlst *new)
{
	t_dlst	*last;

	if (!dlst || !new)
		return ;
	if (*dlst)
	{
		last = ft_dlstlast(*dlst);
		last->next = new;
		new->prev = last;
	}
	else
		*dlst = new;
}
