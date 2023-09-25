/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:48:15 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/24 18:19:15 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	run_order_six(t_double_stack *head_stack)
{
	t_linked_tag	*p;
	int	min_value;

	p = head_stack->stack_a->next;
	min_value = 0;
	if (head_stack->tail_a > 6)
		return ;
	while (head_stack->tail_a > 3)
	{
		if (find_number(head_stack, min_value) == 0)
		{
			min_value++;
			pb(head_stack);
		}
		else if (head_stack->tail_a > 3)
		{
			ra(head_stack);
		}
	}
	// print_list(head_stack->stack_a);
	run_order_thr(head_stack);
	// print_list(head_stack->stack_a);
	while (head_stack->tail_b > 0)
	{
		pa(head_stack);
	}
}