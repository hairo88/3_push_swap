/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tan_houko_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:42 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:15:25 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_linked_tag	*search_tail(t_linked_tag *list)
{
	t_linked_tag	*p;

	p = list;
	while (p->next != list)
	{
		p = p->next;
	}
	return (p);
}

//最初の要素を削除する
int	pop_a(t_double_stack *head_stack)
{
	int				value;
	t_linked_tag	*final;
	t_linked_tag	*sta;
	int				size;

	value = 0;
	size = 0;
	value = head_stack->stack_a->next->value;
	final = search_tail(head_stack->stack_a);
	head_stack->stack_a = head_stack->stack_a->next;
	final->next = head_stack->stack_a;
	sta = head_stack->stack_a->next;
	while (sta->next != head_stack->stack_a->next)
	{
		sta->index -= 1;
		sta = sta->next;
		size++;
	}
	head_stack->tail_a -= 1;
	return (value);
}

int	pop_b(t_double_stack *head_stack)
{
	int				value;
	t_linked_tag	*final;
	t_linked_tag	*sta;
	int				size;

	value = 0;
	size = 0;
	value = head_stack->stack_b->next->value;
	final = search_tail(head_stack->stack_b);
	head_stack->stack_b = head_stack->stack_b->next;
	final->next = head_stack->stack_b;
	sta = head_stack->stack_b->next;
	while (sta->next != head_stack->stack_b->next)
	{
		sta->index -= 1;
		sta = sta->next;
		size++;
	}
	head_stack->tail_b = size;
	return (value);
}

//先頭ノードに追加する
void	add_list_front(t_linked_tag *list, t_linked_tag *add_list)
{
	if (list == NULL)
	{
		list = add_list;
		add_list->next = list;
		return ;
	}
	add_list = list;
	list = add_list;
}
