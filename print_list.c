/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:03:01 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/14 23:42:54 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		lstprint(t_list **lst)
{
	t_node		*cur;

	ft_printf("\033[0m");
	if (lst == NULL || *lst == NULL)
		return ;
	cur = (*lst)->head;
	while (cur)
	{
		ft_printf("% 11d\n", cur->nb);
		cur = cur->next;
	}
}

static void		lstprint_color(t_list **lst, int n)
{
	t_node		*cur;

	if (lst == NULL || *lst == NULL)
		return ;
	ft_printf("\033[0m");
	cur = (*lst)->head;
	while (cur)
	{
		if (n == -1 && cur->index == (*lst)->size)
			ft_printf("\033[1;32m");
		else if (n == cur->index || n - 1 == cur->index)
			ft_printf("\033[1;32m");
		ft_printf("% 11d\n", cur->nb);
		ft_printf("\033[0m");
		cur = cur->next;
	}
}

void			lstupdate_color(t_list **lst_a, t_list **lst_b, char *op)
{
	ft_printf("\033[1;31m");
	ft_printf("List update...\n");
	ft_printf("\033[1;36m");
	ft_printf("List a...\n");
	if (ft_strequ(op, "pa") || ft_strequ(op, "rra"))
		lstprint_color(lst_a, 1);
	else if (ft_strequ(op, "sa"))
		lstprint_color(lst_a, 2);
	else if (ft_strequ(op, "ra"))
		lstprint_color(lst_a, -1);
	else
		lstprint(lst_a);
	ft_printf("\033[1;36m");
	ft_printf("List b...\n");
	ft_printf("\033[0m");
	if (ft_strequ(op, "pb") || ft_strequ(op, "rrb"))
		lstprint_color(lst_b, 1);
	else if (ft_strequ(op, "sb"))
		lstprint_color(lst_b, 2);
	else if (ft_strequ(op, "rb"))
		lstprint_color(lst_b, -1);
	else
		lstprint(lst_b);
	ft_printf("------------------------------------------\n");
	sleep(1);
}

void			lstupdate(t_list **lst_a, t_list **lst_b)
{
	ft_printf("\033[1;31m");
	ft_printf("List update...\n");
	ft_printf("\033[1;36m");
	ft_printf("List a...\n");
	ft_printf("\033[0m");
	lstprint(lst_a);
	ft_printf("\033[1;36m");
	ft_printf("list b...\n");
	ft_printf("\033[0m");
	lstprint(lst_b);
	ft_printf("------------------------------------------\n");
	sleep(1);
}
