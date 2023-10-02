/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:13:25 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:13:53 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_double_stack *head_stack)
{
	t_linked_tag	*temp_a;
	t_linked_tag	*temp_b;
	t_linked_tag	*last_stack_b;
	t_linked_tag	*last_stack_a;

	temp_b = head_stack->stack_a->next;
	last_stack_b = search_tail(head_stack->stack_a);
	head_stack->stack_a->next = head_stack->stack_a->next->next;
	last_stack_b->next = head_stack->stack_a;
	head_stack->tail_a -= 1;
	temp_a = head_stack->stack_b->next;
	head_stack->stack_b->next = temp_b;
	temp_b->next = temp_a;
	last_stack_a = search_tail(head_stack->stack_b);
	last_stack_a->next = head_stack->stack_b;
	head_stack->tail_b += 1;
	ft_printf("pb\n");
}
