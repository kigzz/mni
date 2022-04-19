/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:32:19 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:32:34 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlst **dlst, t_dlst *new)
{
	if (!dlst || !new)
		return ;
	if (*dlst)
	{
		new->next = *dlst;
		(*dlst)->prev = new;
		*dlst = new;
	}
	else
		*dlst = new;
}
