/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:23:54 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/22 17:24:06 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*new;
	t_list	*head;
	void	*new_content;

	new = NULL;
	head = NULL;
	lst_tmp = lst;
	while (lst_tmp != NULL)
	{
		new_content = f(lst_tmp->content);
		if (new_content != NULL)
		{
			new = ft_lstnew(new_content);
			if (new == NULL)
			{
				ft_lstclear(&lst_tmp, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new);
		}
		lst_tmp = lst_tmp->next;
	}
	return (head);
}
