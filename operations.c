/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:56:14 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 18:16:54 by kotainou         ###   ########.fr       */
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
	t_linked_tag	*p;
	t_linked_tag	*secand_p;
	int				top;

	top = head_stack->stack_a->next->value;
	p = search_tail(head_stack->stack_a);
	secand_p = head_stack->stack_a->next->next;
	p->next = head_stack->stack_a;
	head_stack->stack_a->next = secand_p;
	add_elem(head_stack->stack_a, top);
	ft_printf("ra\n");
}

void	rb(t_double_stack *head_stack)
{
	t_linked_tag	*p;
	t_linked_tag	*secand_p;
	int				top;

	top = head_stack->stack_b->next->value;
	p = search_tail(head_stack->stack_b);
	secand_p = head_stack->stack_b->next->next;
	p->next = head_stack->stack_b;
	head_stack->stack_b->next = secand_p;
	add_elem(head_stack->stack_b, top);
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
	t_linked_tag *current;
	t_linked_tag *prev_tail;

	current = head_stack->stack_a;
	while (current->next != head_stack->stack_a)
	{
		prev_tail = current;
		current = current->next;
	}
	current->next = head_stack->stack_a->next;
	head_stack->stack_a->next = current;
	prev_tail->next = head_stack->stack_a;
	ft_printf("rra\n");
}

void	rrb(t_double_stack *head_stack)
{
	t_linked_tag *current;
	t_linked_tag *prev_tail;

	current = head_stack->stack_b;
	while (current->next != head_stack->stack_b)
	{
		prev_tail = current;
		current = current->next;
	}
	current->next = head_stack->stack_b->next;
	head_stack->stack_b->next = current;
	prev_tail->next = head_stack->stack_b;
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
	// ft_printf("top [%p]\n", list);
	head_stack->stack_a = list;
	// list->value = pop_b(head_stack);
	// ft_printf("list->value[%d]\n", list->value);
	list->next = top;
	top->value = pop_b(head_stack);
	// ft_printf("list->next [%p]\n", list->next);
	tail->next = head_stack->stack_a;
	// ft_printf("head_stack->stack_a[%p]\n", head_stack->stack_a);
	i = 0;
	list = head_stack->stack_a->next;
	while (list != head_stack->stack_a)
	{
		list->index = (int)i;
		list = list->next;
		i++;
	}
	head_stack->tail_a += 1;
	head_stack->tail_b -= 1;
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
	head_stack->stack_b = list;
	list->next = top;
	top->value = pop_a(head_stack);
	tail->next = head_stack->stack_b;
	i = 0;
	list = head_stack->stack_b->next;
	while (list != head_stack->stack_b)
	{
		list->index = (int)i;
		list = list->next;
		i++;
	}
	// head_stack->tail_a -= 1;
	head_stack->tail_b += 1;
	ft_printf("pb\n");
}