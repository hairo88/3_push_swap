/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:25:49 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 18:59:46 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//求める値が上から見た方が早いのか下から見た方が違いのを比べる
//上からの場合は1を返す
int	judg_r_rr(t_linked_tag *list, int value)
{
	t_linked_tag	*p;
	int				top;
	int				size;

	top = 0;
	size = 0;
	p = list->next;
	while (p != list)
	{
		if (value == p->value)
			break ;
		top++;
		p = p->next;
	}
	p = list->next;
	while (p != list)
	{
		p = p->next;
		size++;
	}
	if (top < size / 2)
		return (1);
	return (0);
}

//pbした後にpivot_u30にしたがいってrbする関数
//while文の条件式が間違っている
void	push_and_ra(t_double_stack *head_stack, int pivot_u_10, int pivot_u_30)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (cnt + (head_stack->max_size - head_stack->tail_a) <= pivot_u_30)
	{
		if (head_stack->stack_a->next->value <= pivot_u_30)
		{
			if (head_stack->stack_a->next->value <= pivot_u_10
				&& head_stack->tail_b + 1 >= 2)
			{
				pb(head_stack);
				rb(head_stack, 1);
			}
			else
				pb(head_stack);
			cnt++;
		}
		if (head_stack->stack_a->next->value > pivot_u_30)
			ra(head_stack, 1);
		i++;
	}
}

void	final_stakc(t_double_stack *head_stack)
{
	int		number;

	number = head_stack->tail_b;
	while (head_stack->tail_b > 0)
	{
		if (judg_r_rr(head_stack->stack_b, number))
		{
			while (number != head_stack->stack_b->next->value)
				rb(head_stack, 1);
			pa(head_stack);
		}
		else
		{
			while (number != head_stack->stack_b->next->value)
				rrb(head_stack, 1);
			pa(head_stack);
		}
		number--;
	}
}

void	new_big_sort_main(t_double_stack *head_stack)
{
	int		pivot_u_30;
	int		pivot_u_10;

	while (head_stack->tail_a > 3)
	{
		pivot_u_30 = head_stack->tail_a * 0.3
			+ (head_stack->max_size - head_stack->tail_a);
		pivot_u_10 = head_stack->tail_a * 0.1
			+ (head_stack->max_size - head_stack->tail_a);
		if (head_stack->tail_a == 6)
			pivot_u_30 = 2 + head_stack->max_size - head_stack->tail_a;
		if (head_stack->tail_a == 2)
			pivot_u_30 = head_stack->max_size - head_stack->tail_a;
		push_and_ra(head_stack, pivot_u_10, pivot_u_30);
	}
	run_order_thr(head_stack);
	final_stakc(head_stack);
}
