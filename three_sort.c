/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:46 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/21 21:37:32 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_order_thr(t_double_stack *head_stack)
{
	if (find_number(head_stack, 2) == 1 && find_number(head_stack, 0) == 0)
	{
		rra(head_stack);
		sa(head_stack);
	}
	else if (find_number(head_stack, 2) == 2 && find_number(head_stack, 0) == 1)
		sa(head_stack);
	else if (find_number(head_stack, 2) == 1 && find_number(head_stack, 0) == 2)
		rra(head_stack);
	else if (find_number(head_stack, 2) == 0 && find_number(head_stack, 0) == 1)
	{
		ra(head_stack);
	}
	else if (find_number(head_stack, 2) == 0 && find_number(head_stack, 0) == 2)
	{
		ra(head_stack);
		sa(head_stack);
	}
	// print_list(head_stack->stack_a);
}

// void	thr_sort_main(t_double_stack *head_stack)
// {
// 	run_order_thr(head_stack);
// }

