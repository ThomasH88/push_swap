/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:51:22 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 20:03:36 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			op_swap(t_list **lst)
{
	int		tmp;

	if (lst == NULL || *lst == NULL || (*lst)->size < 2)
		return ;
	tmp = (*lst)->head->nb;
	(*lst)->head->nb = (*lst)->head->next->nb;
	(*lst)->head->next->nb = tmp;
}

void			op_push(t_list **lst1, t_list **lst2)
{
	if (lst1 == NULL || lst2 == NULL || *lst2 == NULL)
		return ;
	lstadd_front(lst1, (*lst2)->head->nb);
	lstdel_elem_front(lst2);
}

void			op_rotate(t_list **lst)
{
	t_node	*cur;
	int		tmp;

	if (lst == NULL || *lst == NULL || (*lst)->size < 2)
		return ;
	if ((*lst)->size == 2)
		return (op_swap(lst));
	cur = (*lst)->head;
	tmp = cur->nb;
	while (cur && cur->next)
	{
		cur->nb = cur->next->nb;
		cur = cur->next;
	}
	cur->nb = tmp;
}

static void		op_rev_rotate_rec(t_node *cur)
{
	int		tmp;

	if (cur == NULL)
		return ;
	tmp = cur->nb;
	cur = cur->next;
	op_rev_rotate_rec(cur);
	if (cur)
		cur->nb = tmp;
}

void			op_rev_rotate(t_list **lst)
{
	t_node	*cur;
	int		tail_nb;

	if (lst == NULL || *lst == NULL || (*lst)->size < 2)
		return ;
	if ((*lst)->size == 2)
		return (op_swap(lst));
	cur = (*lst)->head;
	tail_nb = (*lst)->tail->nb;
	op_rev_rotate_rec(cur);
	(*lst)->head->nb = tail_nb;
}
