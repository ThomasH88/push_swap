/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 09:26:57 by tholzheu          #+#    #+#             */
/*   Updated: 2019/06/15 16:03:59 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

# define MALLOCHECK(addr) if ((addr) == 0) return (0)

typedef struct		s_node
{
	int				nb;
	struct s_node	*next;
	int				index;
	int				offset;
}					t_node;

typedef struct		s_list
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_list;

void				lstupdate(t_list **lst_a, t_list **lst_b);
void				lstupdate_color(t_list **lst_a, t_list **lst_b, char *op);

t_node				*lstnew_node(int nb);
t_list				*lstnew_list(int nb);
void				lstadd_back(t_list **lst, int nb);
void				set_index(t_list **lst);
void				lstadd_front(t_list **lst, int nb);

void				lstdel_elem_front(t_list **lst);
void				lstdel_list(t_list **lst);

t_list				*lstdup_elem(t_list **lst, int n);
t_list				*lstdup(t_list **lst);
void				lstsort(t_list **lst);
void				simplify_list(t_list **lst);

int					is_sorted(t_list **lst_a, t_list **lst_b);
int					error_check(char **argv);
int					find_pivot(t_list **lst, int n);
int					find_index(t_list **lst, int nb);
int					lstsize_total(t_list **lst_a, t_list **lst_b);

int					op_swap_a(t_list **lst_a, t_list **lst_b, int debug);
int					op_push_a(t_list **lst_a, t_list **lst_b, int debug);
int					op_rotate_a(t_list **lst_a, t_list **lst_b, int debug);
int					op_rev_rotate_a(t_list **lst_a, t_list **lst_b, int debug);

int					op_swap_b(t_list **lst_b, t_list **lst_a, int debug);
int					op_push_b(t_list **lst_b, t_list **lst_a, int debug);
int					op_rotate_b(t_list **lst_b, t_list **lst_a, int debug);
int					op_rev_rotate_b(t_list **lst_b, t_list **lst_a, int debug);

int					op_swap_both(t_list **lst_a, t_list **lst_b, int debug);
int					op_rotate_both(t_list **lst_a, t_list **lst_b, int debug);
int					op_rev_rotate_both(t_list **lst_a, t_list **lst_b,
										int debug);
int					execute_instructions(char *inst, t_list **lst_a,
										t_list **lst_b, int debug);
int					swap_check(t_list **lst_a, char **inst);

void				set_offset(t_list **lst);
int					is_shifted_sorted(t_list **lst_a, t_list **lst_b);

void				resolve(t_list **lst_a, t_list **lst_b, int n, int debug);

void				resolve_small(t_list **lst_a, t_list **lst_b, int debug);

#endif
