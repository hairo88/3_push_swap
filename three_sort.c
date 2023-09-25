/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:46 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/25 17:01:00 by kotainou         ###   ########.fr       */
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

void	run_order_two(t_double_stack *head_stack)
{
	t_linked_tag	*p;
	// int				one;

	if (head_stack->tail_a != 2)
		return ;
	p = head_stack->stack_a->next;
	if (p->value > p->next->value)
		sa(head_stack);
}

//この関数はstack_aで適用される
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
	else if (find_number(head_stack, min_value + 2) == 0 && find_number(head_stack, min_value + 0) == 2)
	{
		ra(head_stack);
		sa(head_stack);
	}
	// print_list(head_stack->stack_a);
}

