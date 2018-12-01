/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:07:47 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 17:45:46 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		flags_parsing(char **arr, int *debug, int door)
{
	int		i;

	i = 0;
	*debug = 0;
	while (arr[i])
	{
		if (ft_strequ(arr[i], "-v") && ++i)
			*debug = 2;
		else if (ft_strequ(arr[i], "-c") && ++i)
			*debug = 3;
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

static int		run_checker(char **arr, int door)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*line;
	int		debug;
	int		i;

	lst_a = NULL;
	lst_b = NULL;
	if ((i = flags_parsing(arr, &debug, door)) == -1)
		return (-1);
	while (arr[i])
		lstadd_back(&lst_a, ft_atoi(arr[i++]));
	while (get_next_line(0, &line) > 0)
	{
		if (execute_instructions(line, &lst_a, &lst_b, debug) == -1)
			return (write(2, "Error\n", 6));
		ft_strdel(&line);
	}
	if (door)
		ft_arrdel(&arr);
	if (is_sorted(&lst_a, &lst_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int				main(int argc, char **argv)
{
	char	**arr;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		arr = ft_strsplit(argv[1], ' ');
		if (run_checker(arr, 1) == -1)
			return (write(2, "Error\n", 6));
	}
	else
	{
		if (run_checker(argv + 1, 0) == -1)
			return (write(2, "Error\n", 6));
	}
	return (0);
}
