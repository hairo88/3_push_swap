/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:56:14 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/20 18:28:31 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_double_stack *head_stack)
{
	int				top_value;
	t_linked_tag	*elem;
	t_linked_tag	*third_ptr;
	t_linked_tag	*list;

	elem = (t_linked_tag*)malloc(sizeof(t_linked_tag));
	if (elem == NULL)
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	if (head_stack->tail_a < 2)
	{
		printf("list a のリストが少ない\n");
		exit(1);
	}
	top_value = pop_a(head_stack);
	third_ptr = head_stack->stack_a->next->next;
	head_stack->stack_a->next->next = elem;
	elem->value = top_value;
	elem->next = third_ptr;
	elem->index = head_stack->stack_a->next->index + 1;
	list = head_stack->stack_a->next->next->next;
	while (list != head_stack->stack_a)
	{
		list->index += 1;
		list = list->next;
	}
}

void	sb(t_double_stack *head_stack)
{
	int				top_value;
	t_linked_tag	*elem;
	t_linked_tag	*third_ptr;
	t_linked_tag	*list;

	elem = (t_linked_tag*)malloc(sizeof(t_linked_tag));
	if (elem == NULL)
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	if (head_stack->tail_b < 2)
	{
		printf("list a のリストが少ない\n");
		exit(1);
	}
	top_value = pop_b(head_stack);
	third_ptr = head_stack->stack_b->next->next;
	head_stack->stack_b->next->next = elem;
	elem->value = top_value;
	elem->next = third_ptr;
	elem->index = head_stack->stack_b->next->index + 1;
	list = head_stack->stack_b->next->next->next;
	while (list != head_stack->stack_b)
	{
		list->index += 1;
		list = list->next;
	}
	printf("b\n");
	print_list(head_stack->stack_b);
}

void	ra(t_double_stack *head_stack)
{
	int		top;

	top = head_stack->stack_a->next->value;
	add_elem(head_stack->stack_a, top);
	pop_a(head_stack);
}

void	rb(t_double_stack *head_stack)
{
	add_elem(head_stack->stack_b, head_stack->stack_b->next->value);
	pop_b(head_stack);
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
		printf("メモリ割り当て失敗\n");
		exit(1);
	}
	top = head_stack->stack_a;
	tail = search_tail(head_stack->stack_a);
	printf("top [%p]\n", list);
	head_stack->stack_a = list;
	// list->value = pop_b(head_stack);
	printf("list->value[%d]\n", list->value);
	list->next = top;
	top->value = pop_b(head_stack);
	printf("list->next [%p]\n", list->next);
	tail->next = head_stack->stack_a;
	printf("head_stack->stack_a[%p]\n", head_stack->stack_a);
	i = 0;
	list = head_stack->stack_a->next;
	while (list != head_stack->stack_a)
	{
		list->index = (int)i;
		list = list->next;
		i++;
	}
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
		printf("メモリ割り当て失敗\n");
		exit(1);
	}
	top = head_stack->stack_b;
	tail = search_tail(head_stack->stack_b);
	printf("top [%p]\n", list);
	head_stack->stack_b = list;
	// list->value = pop_a(head_stack);
	printf("list->value[%d]\n", list->value);
	list->next = top;
	top->value = pop_a(head_stack);
	printf("list->next [%p]\n", list->next);
	tail->next = head_stack->stack_b;
	printf("head_stack->stack_b[%p]\n", head_stack->stack_b);
	i = 0;
	list = head_stack->stack_b->next;
	while (list != head_stack->stack_b)
	{
		list->index = (int)i;
		list = list->next;
		i++;
	}
}