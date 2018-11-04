/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:03:01 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 11:06:51 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		lstprint(t_list **lst)
{
	t_node		*cur;

	if (lst == NULL || *lst == NULL)
		return ;
	cur = (*lst)->head;
	while (cur)
	{
		printf("%d\n", cur->nb);
		cur = cur->next;
	}
}
