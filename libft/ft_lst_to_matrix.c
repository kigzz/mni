/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:45:04 by bpouchep          #+#    #+#             */
/*   Updated: 2022/04/19 13:45:05 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttomatrix(t_list *lst)
{
	char	**matrix;
	t_list	*aux;
	char	*temp;

	aux = lst;
	matrix = NULL;
	while (aux)
	{
		temp = ft_strdup(aux->content);
		matrix = ft_matrix_extend(matrix, temp);
		aux = aux->next;
		free(temp);
	}
	return (matrix);
}
