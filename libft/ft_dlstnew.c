/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:51 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:34:53 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstnew(int data)
{
	t_dlst	*newdlst;

	newdlst = (t_dlst *)malloc(sizeof(t_dlst));
	if (!newdlst)
		return (NULL);
	newdlst->data = data;
	newdlst->next = NULL;
	newdlst->prev = NULL;
	return (newdlst);
}
