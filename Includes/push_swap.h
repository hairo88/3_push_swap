/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:01:29 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 19:14:28 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

#include "../libft/libft.h"
#include "../libft/get_next_line/get_next_line.h"
#include "../libft/ft_printf/ft_printf.h"

typedef struct s_linked_tag
{
	int					value;
	int					index;
	struct s_linked_tag	*next;
}	t_linked_tag;

typedef struct s_double_stack
{
	t_linked_tag	*stack_a;
	t_linked_tag	*stack_b;
	int				tail_a;
	int				tail_b;
}	t_double_stack;

typedef struct s_min_max
{
	int	max_index;
	int	max_value;
	int	min_index;
	int	min_value;
}	t_min_max;

t_linked_tag	*create_list(void);
void			delete_list(t_linked_tag *list);
void			clear_list(t_linked_tag *list);
t_linked_tag	*search_tail(t_linked_tag *list);

int				add_elem(t_linked_tag	*list, int value);

void			delete_list(t_linked_tag *list);
void			print_list(t_linked_tag *list);

int				pop_a(t_double_stack *head_stack);
int				pop_b(t_double_stack *head_stack);

//operation.c
void	sa(t_double_stack *head_stack);
void	sb(t_double_stack *head_stack);
void	ra(t_double_stack *head_stack);
void	rb(t_double_stack *head_stack);
void	rra(t_double_stack *head_stack);
void	rrb(t_double_stack *head_stack);
void	pa(t_double_stack *head_stack);
void	pb(t_double_stack *head_stack);
void	ss(t_double_stack *head_stack);
void	rr(t_double_stack *head_stack);
void	rrr(t_double_stack *head_stack);

//check_sort.c
int		is_sorted(t_double_stack *head_stack);

//three_sort.c
void	run_order_thr(t_double_stack *head_stack);
// void	run_order_thr(t_double_stack *head_stack, int max_index, int min_index);

//six_sort.c
void	six_sort_main(t_double_stack *head_stack);

//minizer.c
void	minizer_stack(t_double_stack *head_stack);

//find_number.c
int		find_number(t_double_stack *head_stack, int number);

//input_value.c
void	input_value(t_double_stack *head_stack, int ac, char *av[]);

#endif