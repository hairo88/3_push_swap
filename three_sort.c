/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:46 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:10:16 by kotainou         ###   ########.fr       */
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

int	find_min_value_b(t_double_stack *head_stack)
{
	t_linked_tag	*list;
	int				min_value;

	min_value = INT_MAX;
	list = head_stack->stack_b->next;
	while (list != head_stack->stack_b)
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

	if (head_stack->tail_a != 2)
		return ;
	p = head_stack->stack_a->next;
	if (p->value > p->next->value)
		sa(head_stack, 1);
}

//この関数はstack_aで適用される
void	run_order_thr(t_double_stack *stack)
{
	int		mv;

	if (stack->tail_a != 3)
		return ;
	mv = find_min_value(stack);
	if (find_num(stack, mv + 2) == 1 && find_num(stack, mv + 0) == 0)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (find_num(stack, mv + 2) == 2 && find_num(stack, mv + 0) == 1)
		sa(stack, 1);
	else if (find_num(stack, mv + 2) == 1 && find_num(stack, mv + 0) == 2)
		rra(stack, 1);
	else if (find_num(stack, mv + 2) == 0 && find_num(stack, mv + 0) == 1)
	{
		ra(stack, 1);
	}
	else if (find_num(stack, mv + 2) == 0 && find_num(stack, mv + 0) == 2)
	{
		ra(stack, 1);
		sa(stack, 1);
	}
}

void	run_order_thr_b(t_double_stack *stack)
{
	int		mv;

	if (stack->tail_b != 3)
		return ;
	mv = find_min_value_b(stack);
	if (find_numb(stack, mv + 2) == 1 && find_numb(stack, mv + 0) == 0)
	{
		rrb(stack, 1);
		sb(stack, 1);
	}
	else if (find_numb(stack, mv + 2) == 2 && find_numb(stack, mv + 0) == 1)
		sb(stack, 1);
	else if (find_numb(stack, mv + 2) == 1 && find_numb(stack, mv + 0) == 2)
		rrb(stack, 1);
	else if (find_numb(stack, mv + 2) == 0 && find_numb(stack, mv + 0) == 1)
	{
		rb(stack, 1);
	}
	else if (find_numb(stack, mv + 2) == 0 && find_numb(stack, mv + 0) == 2)
	{
		rb(stack, 1);
		sb(stack, 1);
	}
}
