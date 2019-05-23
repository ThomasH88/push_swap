/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:34:52 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 17:23:12 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		reset_offset(t_list **lst)
{
	t_node	*cur;

	if (lst == NULL || *lst == NULL)
		return (0);
	cur = (*lst)->head;
	while (cur)
	{
		cur->offset = 0;
		cur = cur->next;
	}
	return (1);
}

static void		set_offset_node(t_node **node, int off_up, int off_down)
{
	if (off_up < ft_abs(off_down))
		(*node)->offset = off_up;
	else
		(*node)->offset = off_down;
}

void			set_offset(t_list **lst)
{
	int		off_up;
	int		off_down;
	t_node	*cur;

	if (reset_offset(lst) == 0)
		return ;
	cur = (*lst)->head;
	while (cur)
	{
		off_up = 0;
		off_down = 0;
		if (cur->index < cur->nb)
		{
			off_up = cur->index + ((*lst)->size - cur->nb);
			off_down = cur->index - cur->nb;
		}
		else if (cur->index > cur->nb)
		{
			off_up = cur->index - cur->nb;
			off_down = (cur->index - (*lst)->size) - cur->nb;
		}
		set_offset_node(&cur, off_up, off_down);
		cur = cur->next;
	}
}

int				is_shifted_sorted(t_list **lst_a, t_list **lst_b)
{
	t_node	*cur;
	int		offset;

	if (!lst_a || !*lst_a || lst_b)
		return (-99);
	set_offset(lst_a);
	cur = (*lst_a)->head;
	offset = cur->offset;
	while (cur)
	{
		if (cur->offset != offset)
			return (-99);
		cur = cur->next;
	}
	return (offset);
}
