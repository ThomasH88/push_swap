/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:07:47 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 20:57:24 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		error_check(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
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
	}
	return (0);
}

static int		is_sorted(t_list **lst_a, t_list **lst_b)
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

static int		execute_instructions(char *inst, t_list **lst_a, t_list **lst_b)
{
	if (ft_strcmp(inst, "sa") == 0)
		op_swap(lst_a);
	else if (ft_strcmp(inst, "sb") == 0)
		op_swap(lst_b);
	else if (ft_strcmp(inst, "ss") == 0)
		op_swap_both(lst_a, lst_b);
	else if (ft_strcmp(inst, "pa") == 0)
		op_push(lst_a, lst_b);
	else if (ft_strcmp(inst, "pb") == 0)
		op_push(lst_b, lst_a);
	else if (ft_strcmp(inst, "ra") == 0)
		op_rotate(lst_a);
	else if (ft_strcmp(inst, "rb") == 0)
		op_rotate(lst_b);
	else if (ft_strcmp(inst, "rr") == 0)
		op_rotate_both(lst_a, lst_b);
	else if (ft_strcmp(inst, "rra") == 0)
		op_rev_rotate(lst_a);
	else if (ft_strcmp(inst, "rrb") == 0)
		op_rev_rotate(lst_b);
	else if (ft_strcmp(inst, "rrr") == 0)
		op_rev_rotate_both(lst_a, lst_b);
	else
		return (-1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;
	char	*line;

	if (argc == 1)
		return (0);
	if (error_check(argv) == -1)
		return (write(2, "Error\n", 6));
	lst_a = NULL;
	lst_b = NULL;
	i = 0;
	while (argv[++i])
		lstadd_back(&lst_a, ft_atoi(argv[i]));
	while (get_next_line(0, &line) > 0)
	{
		if (execute_instructions(line, &lst_a, &lst_b) == -1)
			return (write(2, "Error\n", 6));
		printf("printing list a...\n");
		lstprint(&lst_a);
		printf("printing list b...\n");
		lstprint(&lst_b);
		ft_strdel(&line);
	}
	if (is_sorted(&lst_a, &lst_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
