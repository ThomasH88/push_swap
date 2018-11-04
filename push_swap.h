/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 09:26:57 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 20:21:51 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/b_printf/b_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h> 
# include <stdio.h>//klajskldjfkajsdkjfklasjlkjf

# define MALLOCHECK(addr) if ((addr) == 0) return (0)

typedef struct		s_node
{
	int				nb;
	struct s_node	*next;
}					t_node;

typedef struct		s_list
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_list;

void				lstprint(t_list **lst);//lkajsdlkfjaklsdjklfjalksjdfja

/*list*/
t_node				*lstnew_node(int nb);
t_list				*lstnew_list(int nb);
void				lstadd_back(t_list **lst, int nb);
void				lstadd_front(t_list **lst, int nb);

/*lstdel*/
void				lstdel_elem_front(t_list **lst);
void				lstdel_list(t_list **lst);

/*operations*/
void				op_swap(t_list **lst);
void				op_push(t_list **lst1, t_list **lst2);//from list 2 to list 1
void				op_rotate(t_list **lst);
void				op_rev_rotate(t_list **lst);

/*multi_operations*/
void				op_swap_both(t_list **lst_a, t_list **lst_b);
void				op_rotate_both(t_list **lst_a, t_list **lst_b);
void				op_rev_rotate_both(t_list **lst_a, t_list **lst_b);


#endif
