/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:56:14 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/13 16:47:55 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_linked_tag	*ra(t_linked_tag *stack_a, t_double_stack *head_stack)
{
	// int		bottom_num;
	int				top_num;
	t_linked_tag	*now_stack;

	(void)head_stack;
	now_stack = stack_a->next;
	// printf("stack_a = [%p]\n", stack_a);
	// stack_a = head_stack->stack_a;
	top_num = now_stack->value;
	// printf("top_num %d\n", top_num);
	//トップの要素をlistの最後に追加
	add_elem(stack_a, top_num);
	printf("add_elem\n");
	print_list(stack_a);
	printf("add_elem finished\n");
	//トップの要素を削除
	pop(stack_a, head_stack);
	return (NULL);
}