/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:30:26 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 18:42:10 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			lstdel_elem_front(t_list **lst)
{
	t_node	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = (*lst)->head->next;
	free((*lst)->head);
	(*lst)->head = NULL;
	(*lst)->head = tmp;
	if ((*lst)->size == 1)
	{
		free(*lst);
		*lst = NULL;
	}
	else
		(*lst)->size--;
}

void			lstdel_list(t_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return ;
	while (lst && *lst)
		lstdel_elem_front(lst);
}
