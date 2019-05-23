/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:43:29 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 20:31:14 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		op_concat(t_list **lst, char **inst, int *i, int door)
{
	set_offset(lst);
	if (door == 1 && swap_check(lst, &inst[*i]) == 0)
	{
		inst[*i] = ft_strdup("rra");
		op_rev_rotate_a(lst, NULL, 0);
	}
	else if (door == 0 && swap_check(lst, &inst[*i]) == 0)
	{
		inst[*i] = ft_strdup("ra");
		op_rotate_a(lst, NULL, 0);
	}
	(*i)++;
	inst[*i] = NULL;
}

static int		sort_small(t_list **lst, char **inst1, char **inst2, int *door)
{
	int		rot1;
	int		rot2;
	t_list	*dup1;
	t_list	*dup2;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	if (lst == NULL || *lst == NULL || (dup1 = lstdup(lst)) == NULL)
		return (0);
	if ((dup2 = lstdup(lst)) == NULL)
		return (0);
	while ((rot1 = is_shifted_sorted(&dup1, NULL)) == -99)
		op_concat(&dup1, inst1, &i[0], 1);
	while ((rot2 = is_shifted_sorted(&dup2, NULL)) == -99)
		op_concat(&dup2, inst2, &i[1], 0);
	lstdel_list(&dup1);
	lstdel_list(&dup2);
	if (ft_arrlen(inst1) < ft_arrlen(inst2))
	{
		*door = 1;
		return (rot1);
	}
	*door = 2;
	return (rot2);
}

static char		**init_arr(void)
{
	int		i;
	char	**inst;

	i = 0;
	if ((inst = (char **)malloc(sizeof(char *) * 25)) == NULL)
		return (NULL);
	inst[24] = NULL;
	return (inst);
}

static void		execute_small(t_list **lst_a, t_list **lst_b,
								char **inst, int debug)
{
	int		j;

	j = 0;
	while (inst && inst[j])
		execute_instructions(inst[j++], lst_a, lst_b, debug);
}

void			resolve_small(t_list **lst_a, t_list **lst_b, int debug)
{
	int		rot;
	int		i;
	char	**inst1;
	char	**inst2;
	int		door;

	inst1 = init_arr();
	inst2 = init_arr();
	rot = sort_small(lst_a, inst1, inst2, &door);
	i = 0;
	if (door == 1)
		execute_small(lst_a, lst_b, inst1, debug);
	else if (door == 2)
		execute_small(lst_a, lst_b, inst2, debug);
	ft_arrdel_size(&inst1, 25);
	ft_arrdel_size(&inst2, 25);
	while (rot < 0 && ++i <= ft_abs(rot))
		op_rev_rotate_a(lst_a, lst_b, debug);
	while (rot > 0 && ++i <= ft_abs(rot))
		op_rotate_a(lst_a, lst_b, debug);
}
