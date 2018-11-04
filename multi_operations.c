/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:05:51 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 20:09:11 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		op_swap_both(t_list **lst_a, t_list **lst_b)
{
	op_swap(lst_a);
	op_swap(lst_b);
}

void		op_rotate_both(t_list **lst_a, t_list **lst_b)
{
	op_rotate(lst_a);
	op_rotate(lst_b);
}

void		op_rev_rotate_both(t_list **lst_a, t_list **lst_b)
{
	op_rev_rotate(lst_a);
	op_rev_rotate(lst_b);
}
