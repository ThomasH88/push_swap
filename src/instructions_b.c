/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:11:19 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/14 23:23:21 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				op_swap_b(t_list **lst_b, t_list **lst_a, int debug)
{
	int		tmp;

	if (lst_b == NULL || *lst_b == NULL || (*lst_b)->size < 2)
		return (0);
	tmp = (*lst_b)->head->nb;
	(*lst_b)->head->nb = (*lst_b)->head->next->nb;
	(*lst_b)->head->next->nb = tmp;
	if (debug == 1)
		write(1, "sb\n", 3);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "sb");
	return (1);
}

int				op_push_b(t_list **lst_b, t_list **lst_a, int debug)
{
	if (lst_b == NULL || lst_a == NULL || *lst_a == NULL)
		return (0);
	lstadd_front(lst_b, (*lst_a)->head->nb);
	lstdel_elem_front(lst_a);
	if (debug == 1)
		write(1, "pb\n", 3);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "pb");
	return (1);
}

int				op_rotate_b(t_list **lst_b, t_list **lst_a, int debug)
{
	t_node	*cur;
	int		tmp;

	if (lst_b == NULL || *lst_b == NULL || (*lst_b)->size < 2)
		return (0);
	if ((*lst_b)->size == 2)
		return (op_swap_b(lst_b, lst_a, debug));
	cur = (*lst_b)->head;
	tmp = cur->nb;
	while (cur && cur->next)
	{
		cur->nb = cur->next->nb;
		cur = cur->next;
	}
	cur->nb = tmp;
	if (debug == 1)
		write(1, "rb\n", 3);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "rb");
	return (1);
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

int				op_rev_rotate_b(t_list **lst_b, t_list **lst_a, int debug)
{
	t_node	*cur;
	int		tail_nb;

	if (lst_b == NULL || *lst_b == NULL || (*lst_b)->size < 2)
		return (0);
	if ((*lst_b)->size == 2)
		return (op_swap_b(lst_b, lst_a, debug));
	cur = (*lst_b)->head;
	tail_nb = (*lst_b)->tail->nb;
	op_rev_rotate_rec(cur);
	(*lst_b)->head->nb = tail_nb;
	if (debug == 1)
		write(1, "rrb\n", 4);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "rrb");
	return (1);
}
