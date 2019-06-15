/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:59:46 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 20:30:16 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		skip_flags(char **arr, int door)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strequ(arr[i], "-v"))
			i++;
		else if (ft_strequ(arr[i], "-c"))
			i++;
		else
			break ;
	}
	if (error_check(&arr[i]) == -1)
	{
		if (door)
			ft_arrdel(&arr);
		return (-1);
	}
	return (i);
}

static int		run_push_swap(t_list **lst_a, t_list **lst_b,
								char **arr, int door)
{
	int		i;

	if ((i = skip_flags(arr, door)) == -1)
		return (-1);
	while (arr[i])
		lstadd_back(lst_a, ft_atoi(arr[i++]));
	simplify_list(lst_a);
	if (is_sorted(lst_a, lst_b))
	{
		if (door)
			ft_arrdel(&arr);
		return (1);
	}
	if ((*lst_a)->size <= 7)
		resolve_small(lst_a, lst_b, 1);
	else
		resolve(lst_a, lst_b, (*lst_a)->size, 1);
	if (door)
		ft_arrdel(&arr);
	return (1);
}

int				main(int argc, char **argv)
{
	char	**arr;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		arr = ft_strsplit(argv[1], ' ');
		if (run_push_swap(&lst_a, &lst_b, arr, 1) == -1)
			return (write(2, "Error\n", 6));
	}
	else
	{
		if (run_push_swap(&lst_a, &lst_b, argv + 1, 0) == -1)
			return (write(2, "Error\n", 6));
	}
	return (0);
}
