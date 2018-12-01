/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstextras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:08:22 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 13:39:22 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*lstdup_elem(t_list **lst, int n)
{
	t_list	*new;
	t_node	*cur;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	cur = (*lst)->head;
	new = NULL;
	while (n-- && cur)
	{
		lstadd_back(&new, cur->nb);
		cur = cur->next;
	}
	return (new);
}

t_list		*lstdup(t_list **lst)
{
	t_list	*new;
	t_node	*cur;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	cur = (*lst)->head;
	new = NULL;
	while (cur)
	{
		lstadd_back(&new, cur->nb);
		cur = cur->next;
	}
	return (new);
}

void		lstsort(t_list **lst)
{
	t_node	*cur;
	int		swap;
	int		tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	swap = 1;
	while (swap)
	{
		swap = 0;
		cur = (*lst)->head;
		while (cur && cur->next)
		{
			if (cur->nb > cur->next->nb)
			{
				tmp = cur->nb;
				cur->nb = cur->next->nb;
				cur->next->nb = tmp;
				swap = 1;
			}
			cur = cur->next;
		}
	}
}

void		simplify_list(t_list **lst)
{
	t_list	*dup;
	t_node	*cur_dup;
	t_node	*cur_lst;

	if (lst == NULL || *lst == NULL || (dup = lstdup(lst)) == NULL)
		return ;
	cur_lst = (*lst)->head;
	lstsort(&dup);
	while (cur_lst)
	{
		cur_dup = dup->head;
		while (cur_dup)
		{
			if (cur_dup->nb == cur_lst->nb && cur_lst->offset == 0)
			{
				cur_lst->nb = cur_dup->index;
				cur_lst->offset = 1;
			}
			cur_dup = cur_dup->next;
		}
		cur_lst = cur_lst->next;
	}
	lstdel_list(&dup);
}
