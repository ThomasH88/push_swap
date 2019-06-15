/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:38:55 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 14:44:51 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		insert_sort(t_list **lst_a, t_list **lst_b, int n, int debug)
{
	int		tmp;

	while (n)
	{
		if ((*lst_a)->tail->nb == lstsize_total(lst_a, lst_b))
			tmp = 0;
		else
			tmp = (*lst_a)->tail->nb;
		if (((*lst_a)->size == 1 && n--) ||
((*lst_b)->head->nb < (*lst_a)->head->nb && ((*lst_b)->head->nb > tmp) && n--))
			op_push_a(lst_a, lst_b, debug);
		else if ((*lst_b)->head->nb < (*lst_a)->head->nb)
			op_rev_rotate_a(lst_a, lst_b, debug);
		else if ((*lst_b)->head->nb > tmp)
			op_rotate_a(lst_a, lst_b, debug);
	}
	while ((*lst_a)->tail->nb != lstsize_total(lst_a, lst_b))
	{
		tmp = find_index(lst_a, lstsize_total(lst_a, lst_b));
		if ((*lst_a)->size - tmp < tmp)
			op_rev_rotate_a(lst_a, lst_b, debug);
		else
			op_rotate_a(lst_a, lst_b, debug);
	}
	return (1);
}

static int		push_half(t_list **lst_a, t_list **lst_b,
						int *rotback, int pivot)
{
	if ((*lst_a)->head->nb <= pivot)
	{
		op_push_b(lst_b, lst_a, 1);
		return (1);
	}
	else if (++(*rotback))
	{
		op_rotate_a(lst_a, lst_b, 1);
		return (0);
	}
	return (0);
}

void			resolve(t_list **lst_a, t_list **lst_b, int n,
						int debug)
{
	int		pivot;
	int		rotback;
	int		count;
	int		tmp;
	int		i;

	if (lst_a == NULL || *lst_a == NULL)
		return ;
	if (n <= 1)
		return ;
	count = 0;
	rotback = 0;
	pivot = find_pivot(lst_a, n);
	tmp = n / 2 + n % 2;
	while (count < tmp)
		(push_half(lst_a, lst_b, &rotback, pivot)) ? ++count : 0;
	while (*lst_a && (*lst_a)->size > n && rotback--)
		op_rev_rotate_a(lst_a, lst_b, debug);
	resolve(lst_a, lst_b, n / 2, debug);
	if (tmp <= 25 && insert_sort(lst_a, lst_b, tmp, debug))
		return ;
	i = 0;
	while (i++ < tmp)
		op_push_a(lst_a, lst_b, debug);
	resolve(lst_a, lst_b, tmp, debug);
}
