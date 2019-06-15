/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:22:02 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 01:12:34 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_list **lst_a, t_list **lst_b)
{
	t_node	*cur;

	if (lst_a == NULL || *lst_a == NULL)
		return (0);
	cur = (*lst_a)->head;
	while (cur && cur->next)
	{
		if (cur->nb > cur->next->nb)
			return (0);
		cur = cur->next;
	}
	if (lst_b && *lst_b == NULL)
		return (1);
	return (0);
}

int		error_check(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 1;
		if (ft_isnum(argv[i]) == 0)
			return (-1);
		if (argv[i][0] != '0' && ft_atoi(argv[i]) == 0)
			return (-1);
		while (argv[j])
		{
			if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		find_pivot(t_list **lst, int n)
{
	t_list	*dup;
	t_node	*cur;
	int		tmp;

	if (lst == NULL || *lst == NULL || (dup = lstdup_elem(lst, n)) == NULL)
		return (0);
	simplify_list(&dup);
	tmp = dup->size / 2 + dup->size % 2;
	cur = dup->head;
	while (cur->nb != tmp)
		cur = cur->next;
	tmp = cur->index;
	cur = (*lst)->head;
	while (cur->index != tmp)
		cur = cur->next;
	tmp = cur->nb;
	lstdel_list(&dup);
	return (tmp);
}

int		find_index(t_list **lst, int nb)
{
	t_node	*cur;

	if (lst == NULL || *lst == NULL)
		return (-1);
	cur = (*lst)->head;
	while (cur)
	{
		if (cur->nb == nb)
			return (cur->index);
		cur = cur->next;
	}
	return (-1);
}

int		lstsize_total(t_list **lst_a, t_list **lst_b)
{
	int		count;

	count = 0;
	if (lst_a && *lst_a)
		count += (*lst_a)->size;
	if (lst_b && *lst_b)
		count += (*lst_b)->size;
	return (count);
}
