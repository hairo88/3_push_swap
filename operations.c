/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:56:14 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:12:48 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_double_stack *head_stack, int n)
{
	int		tmp;

	tmp = 0;
	if (head_stack->tail_a > 1)
	{
		tmp = head_stack->stack_a->next->value;
		head_stack->stack_a->next->value
			= head_stack->stack_a->next->next->value;
		head_stack->stack_a->next->next->value = tmp;
	}
	if (n == 1)
		ft_printf("sa\n");
}

void	sb(t_double_stack *head_stack, int n)
{
	int		tmp;

	tmp = 0;
	if (head_stack->tail_b > 1)
	{
		tmp = head_stack->stack_b->next->value;
		head_stack->stack_b->next->value
			= head_stack->stack_b->next->next->value;
		head_stack->stack_b->next->next->value = tmp;
	}
	if (n == 1)
		ft_printf("sb\n");
}

void	ss(t_double_stack *head_stack)
{
	sa(head_stack, 0);
	sb(head_stack, 0);
	ft_printf("ss\n");
}

void	ra(t_double_stack *head_stack, int n)
{
	t_linked_tag	*tail_p;
	t_linked_tag	*top_p;

	if (head_stack->tail_a < 2)
		return ;
	tail_p = search_tail(head_stack->stack_a);
	top_p = head_stack->stack_a->next;
	head_stack->stack_a->next = head_stack->stack_a->next->next;
	tail_p->next = top_p;
	top_p->next = head_stack->stack_a;
	if (n == 1)
		ft_printf("ra\n");
}

void	rb(t_double_stack *head_stack, int n)
{
	t_linked_tag	*tail_p;
	t_linked_tag	*top_p;

	if (head_stack->tail_a < 2)
		return ;
	tail_p = search_tail(head_stack->stack_b);
	top_p = head_stack->stack_b->next;
	head_stack->stack_b->next = head_stack->stack_b->next->next;
	tail_p->next = top_p;
	top_p->next = head_stack->stack_b;
	if (n == 1)
		ft_printf("rb\n");
}
