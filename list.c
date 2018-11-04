/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 10:43:13 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 18:42:03 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node			*lstnew_node(int nb)
{
	t_node		*new;

	MALLOCHECK(new = (t_node *)malloc(sizeof(t_node)));
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_list			*lstnew_list(int nb)
{
	t_list		*lst;
	t_node		*new;

	MALLOCHECK(lst = (t_list *)malloc(sizeof(t_list)));
	MALLOCHECK(new = lstnew_node(nb));
	lst->head = new;
	lst->tail = new;
	lst->size = 1;
	return (lst);
}

void			lstadd_back(t_list **lst, int nb)
{
	t_node		*new;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = lstnew_list(nb);
	else
	{
		if ((new = lstnew_node(nb)) == NULL)
			return ;
		(*lst)->tail->next = new;
		(*lst)->tail = new;
		(*lst)->size++;
	}
}

void			lstadd_front(t_list **lst, int nb)
{
	t_node		*new;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = lstnew_list(nb);
	else
	{
		if ((new = lstnew_node(nb)) == NULL)
			return ;
		new->next = (*lst)->head;
		(*lst)->head = new;
		(*lst)->size++;
	}
}
