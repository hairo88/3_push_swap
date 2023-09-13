/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:01:29 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/13 16:46:24 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#include "libft/libft.h"
#include "libft/get_next_line/get_next_line.h"
#include "libft/ft_printf/ft_printf.h"

typedef struct s_linked_tag
{
	int					value;
	// int					tail;
	struct s_linked_tag	*next;
}	t_linked_tag;

typedef struct s_double_stack
{
	t_linked_tag	*stack_a;
	t_linked_tag	*stack_b;
	int				tail_a;
	int				tail_b;
}	t_double_stack;


t_linked_tag	*create_list(void);
void			delete_list(t_linked_tag *list);
void			clear_list(t_linked_tag *list);
void			add_elem(t_linked_tag	*list, int value);
void			delete_list(t_linked_tag *list);
void			print_list(t_linked_tag *list);
t_linked_tag	*pop(t_linked_tag *list);

//operation.c
t_linked_tag	*ra(t_linked_tag *stack_a, t_double_stack *head_stack);

#endif