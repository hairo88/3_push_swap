/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:10:48 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:13:59 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_double_stack *head_stack)
{
	ra(head_stack, 0);
	rb(head_stack, 0);
	ft_printf("rr\n");
}

void	rra(t_double_stack *head_stack, int n)
{
	t_linked_tag	*current;
	t_linked_tag	*prev_tail;

	current = head_stack->stack_a;
	while (current->next != head_stack->stack_a)
	{
		prev_tail = current;
		current = current->next;
	}
	current->next = head_stack->stack_a->next;
	head_stack->stack_a->next = current;
	prev_tail->next = head_stack->stack_a;
	if (n == 1)
		ft_printf("rra\n");
}

void	rrb(t_double_stack *head_stack, int n)
{
	t_linked_tag	*current;
	t_linked_tag	*prev_tail;

	current = head_stack->stack_b;
	while (current->next != head_stack->stack_b)
	{
		prev_tail = current;
		current = current->next;
	}
	current->next = head_stack->stack_b->next;
	head_stack->stack_b->next = current;
	prev_tail->next = head_stack->stack_b;
	if (n == 1)
		ft_printf("rrb\n");
}

void	rrr(t_double_stack *head_stack)
{
	rra(head_stack, 0);
	rrb(head_stack, 0);
	ft_printf("rrr\n");
}

void	pa(t_double_stack *head_stack)
{
	t_linked_tag	*temp_a;
	t_linked_tag	*temp_b;
	t_linked_tag	*last_stack_b;
	t_linked_tag	*last_stack_a;

	temp_b = head_stack->stack_b->next;
	last_stack_b = search_tail(head_stack->stack_b);
	head_stack->stack_b->next = head_stack->stack_b->next->next;
	last_stack_b->next = head_stack->stack_b;
	head_stack->tail_b -= 1;
	temp_a = head_stack->stack_a->next;
	head_stack->stack_a->next = temp_b;
	temp_b->next = temp_a;
	last_stack_a = search_tail(head_stack->stack_a);
	last_stack_a->next = head_stack->stack_a;
	head_stack->tail_a += 1;
	ft_printf("pa\n");
}
