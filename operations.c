/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:56:14 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/21 18:44:50 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_double_stack *head_stack)
{
	int		tmp;

	tmp = 0;
	if (head_stack->tail_a > 1)
	{
		tmp = head_stack->stack_a->next->value;
		head_stack->stack_a->next->value = head_stack->stack_a->next->next->value;
		head_stack->stack_a->next->next->value = tmp;
	}
	ft_printf("sa\n");
}

void	sb(t_double_stack *head_stack)
{
	int		tmp;

	tmp = 0;
	if (head_stack->tail_b > 1)
	{
		tmp = head_stack->stack_b->next->value;
		head_stack->stack_b->next->value = head_stack->stack_b->next->next->value;
		head_stack->stack_b->next->next->value = tmp;
	}
	ft_printf("sb\n");
}

void	ss(t_double_stack *head_stack)
{
	sa(head_stack);
	sb(head_stack);
	ft_printf("ss\n");
}

void	ra(t_double_stack *head_stack)
{
	int		top;

	top = head_stack->stack_a->next->value;
	add_elem(head_stack->stack_a, top);
	pop_a(head_stack);
	ft_printf("ra\n");
}

void	rb(t_double_stack *head_stack)
{
	add_elem(head_stack->stack_b, head_stack->stack_b->next->value);
	pop_b(head_stack);
	ft_printf("rb\n");
}

void	rr(t_double_stack *head_stack)
{
	ra(head_stack);
	rb(head_stack);
	ft_printf("rr\n");
}

void	rra(t_double_stack *head_stack)
{
	t_linked_tag	*tmp;
	t_linked_tag	*tail;

	tmp = head_stack->stack_a;
	tail = search_tail(head_stack->stack_a);
	head_stack->stack_a = tail;
	head_stack->stack_b->next->value = tail->value;
	head_stack->stack_a->next = tmp;
	ft_printf("rra\n");
}

void	rrb(t_double_stack *head_stack)
{
	t_linked_tag	*tmp;
	t_linked_tag	*tail;

	tmp = head_stack->stack_b;
	tail = search_tail(head_stack->stack_b);
	head_stack->stack_b = tail;
	head_stack->stack_b->next->value = tail->value;
	head_stack->stack_b->next = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_double_stack *head_stack)
{
	rra(head_stack);
	rrb(head_stack);
	ft_printf("rrr\n");
}

void	pa(t_double_stack *head_stack)
{
	t_linked_tag	*list;
	t_linked_tag	*top;
	t_linked_tag	*tail;
	size_t			i;

	list = (t_linked_tag*)malloc(sizeof(t_linked_tag));
	if (list == NULL)
	{
		ft_printf("メモリ割り当て失敗\n");
		exit(1);
	}
	top = head_stack->stack_a;
	tail = search_tail(head_stack->stack_a);
	ft_printf("top [%p]\n", list);
	head_stack->stack_a = list;
	// list->value = pop_b(head_stack);
	ft_printf("list->value[%d]\n", list->value);
	list->next = top;
	top->value = pop_b(head_stack);
	ft_printf("list->next [%p]\n", list->next);
	tail->next = head_stack->stack_a;
	ft_printf("head_stack->stack_a[%p]\n", head_stack->stack_a);
	i = 0;
	list = head_stack->stack_a->next;
	while (list != head_stack->stack_a)
	{
		list->index = (int)i;
		list = list->next;
		i++;
	}
	ft_printf("pa\n");
}

void	pb(t_double_stack *head_stack)
{
	t_linked_tag	*list;
	t_linked_tag	*top;
	t_linked_tag	*tail;
	size_t			i;

	list = (t_linked_tag*)malloc(sizeof(t_linked_tag));
	if (list == NULL)
	{
		ft_printf("メモリ割り当て失敗\n");
		exit(1);
	}
	top = head_stack->stack_b;
	tail = search_tail(head_stack->stack_b);
	ft_printf("top [%p]\n", list);
	head_stack->stack_b = list;
	// list->value = pop_a(head_stack);
	ft_printf("list->value[%d]\n", list->value);
	list->next = top;
	top->value = pop_a(head_stack);
	ft_printf("list->next [%p]\n", list->next);
	tail->next = head_stack->stack_b;
	ft_printf("head_stack->stack_b[%p]\n", head_stack->stack_b);
	i = 0;
	list = head_stack->stack_b->next;
	while (list != head_stack->stack_b)
	{
		list->index = (int)i;
		list = list->next;
		i++;
	}
	ft_printf("pb\n");
}