/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:23:49 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/14 23:23:38 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				op_swap_a(t_list **lst_a, t_list **lst_b, int debug)
{
	int		tmp;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->size < 2)
		return (0);
	tmp = (*lst_a)->head->nb;
	(*lst_a)->head->nb = (*lst_a)->head->next->nb;
	(*lst_a)->head->next->nb = tmp;
	if (debug == 1)
		write(1, "sa\n", 3);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "sa");
	return (1);
}

int				op_push_a(t_list **lst_a, t_list **lst_b, int debug)
{
	if (lst_a == NULL || lst_b == NULL || *lst_b == NULL)
		return (0);
	lstadd_front(lst_a, (*lst_b)->head->nb);
	lstdel_elem_front(lst_b);
	if (debug == 1)
		write(1, "pa\n", 3);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "pa");
	return (1);
}

int				op_rotate_a(t_list **lst_a, t_list **lst_b, int debug)
{
	t_node	*cur;
	int		tmp;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->size < 2)
		return (0);
	if ((*lst_a)->size == 2)
		return (op_swap_a(lst_a, lst_b, debug));
	cur = (*lst_a)->head;
	tmp = cur->nb;
	while (cur && cur->next)
	{
		cur->nb = cur->next->nb;
		cur = cur->next;
	}
	cur->nb = tmp;
	if (debug == 1)
		write(1, "ra\n", 3);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "ra");
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

int				op_rev_rotate_a(t_list **lst_a, t_list **lst_b, int debug)
{
	t_node	*cur;
	int		tail_nb;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->size < 2)
		return (0);
	if ((*lst_a)->size == 2)
		return (op_swap_a(lst_a, lst_b, debug));
	cur = (*lst_a)->head;
	tail_nb = (*lst_a)->tail->nb;
	op_rev_rotate_rec(cur);
	(*lst_a)->head->nb = tail_nb;
	if (debug == 1)
		write(1, "rra\n", 4);
	if (debug == 2)
		lstupdate(lst_a, lst_b);
	if (debug == 3)
		lstupdate_color(lst_a, lst_b, "rra");
	return (1);
}
