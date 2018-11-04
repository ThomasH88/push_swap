/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:59:46 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 21:04:20 by tholzheu         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (error_check(argv) == -1)
		return (write(2, "Error\n", 6));
	return (0);
}
