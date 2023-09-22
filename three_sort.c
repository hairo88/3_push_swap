/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:46 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 18:19:23 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_double_stack *head_stack)
{
	t_linked_tag	*list;
	int				min_value;

	min_value = INT_MAX;
	list = head_stack->stack_a->next;
	while (list != head_stack->stack_a)
	{
		if (min_value > list->value)
		{
			min_value = list->value;
		}
		list = list->next;
	}
	return (min_value);
}

void	run_order_thr(t_double_stack *head_stack)
{
	int		min_value;

	if (head_stack->tail_a != 3)
		return ;
	min_value = find_min_value(head_stack);
	if (find_number(head_stack, min_value + 2) == 1 && find_number(head_stack, min_value + 0) == 0)
	{
		rra(head_stack);
		sa(head_stack);
	}
	else if (find_number(head_stack, min_value + 2) == 2 && find_number(head_stack, min_value + 0) == 1)
		sa(head_stack);
	else if (find_number(head_stack, min_value + 2) == 1 && find_number(head_stack, min_value + 0) == 2)
		rra(head_stack);
	else if (find_number(head_stack, min_value + 2) == 0 && find_number(head_stack, min_value + 0) == 1)
	{
		ra(head_stack);
	}
	else if (find_number(head_stack, 2) == 0 && find_number(head_stack, 0) == 2)
	{
		sa(head_stack);
		ra(head_stack);
	}
	// print_list(head_stack->stack_a);
}

// void	thr_sort_main(t_double_stack *head_stack)
// {
// 	run_order_thr(head_stack);
// }

