/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:05:51 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 20:30:34 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			op_swap_both(t_list **lst_a, t_list **lst_b, int debug)
{
	op_swap_a(lst_a, lst_b, debug);
	op_swap_b(lst_b, lst_a, debug);
	return (1);
}

int			op_rotate_both(t_list **lst_a, t_list **lst_b, int debug)
{
	op_rotate_a(lst_a, lst_b, debug);
	op_rotate_b(lst_b, lst_a, debug);
	return (1);
}

int			op_rev_rotate_both(t_list **lst_a, t_list **lst_b, int debug)
{
	op_rev_rotate_a(lst_a, lst_b, debug);
	op_rev_rotate_b(lst_b, lst_a, debug);
	return (1);
}

int			execute_instructions(char *inst, t_list **lst_a,
									t_list **lst_b, int debug)
{
	if (ft_strcmp(inst, "sa") == 0)
		op_swap_a(lst_a, lst_b, debug);
	else if (ft_strcmp(inst, "sb") == 0)
		op_swap_b(lst_b, lst_a, debug);
	else if (ft_strcmp(inst, "ss") == 0)
		op_swap_both(lst_a, lst_b, debug);
	else if (ft_strcmp(inst, "pa") == 0)
		op_push_a(lst_a, lst_b, debug);
	else if (ft_strcmp(inst, "pb") == 0)
		op_push_b(lst_b, lst_a, debug);
	else if (ft_strcmp(inst, "ra") == 0)
		op_rotate_a(lst_a, lst_b, debug);
	else if (ft_strcmp(inst, "rb") == 0)
		op_rotate_b(lst_b, lst_a, debug);
	else if (ft_strcmp(inst, "rr") == 0)
		op_rotate_both(lst_a, lst_b, debug);
	else if (ft_strcmp(inst, "rra") == 0)
		op_rev_rotate_a(lst_a, lst_b, debug);
	else if (ft_strcmp(inst, "rrb") == 0)
		op_rev_rotate_b(lst_b, lst_a, debug);
	else if (ft_strcmp(inst, "rrr") == 0)
		op_rev_rotate_both(lst_a, lst_b, debug);
	else
		return (-1);
	return (0);
}

int			swap_check(t_list **lst_a, char **inst)
{
	if (*lst_a && (*lst_a)->head->next &&
		(*lst_a)->head->next->nb == (*lst_a)->size && (*lst_a)->head->nb == 1)
	{
		*inst = ft_strdup("sa");
		op_swap_a(lst_a, NULL, 0);
		return (1);
	}
	else if ((*lst_a)->head->nb == (*lst_a)->size &&
			(*lst_a)->head->next->nb == 1)
		return (0);
	else if (*lst_a && (*lst_a)->head->next &&
		(*lst_a)->head->nb > (*lst_a)->head->next->nb)
	{
		*inst = ft_strdup("sa");
		op_swap_a(lst_a, NULL, 0);
		return (1);
	}
	return (0);
}
