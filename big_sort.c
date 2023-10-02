/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:15:54 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:41 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//先頭にある値とpivotを比べてpivotより小さい場合 1を返す
int	check_first_value(t_linked_tag *list, int pivot)
{
	int		ans;

	ans = 0;
	if (list->next->value <= pivot)
		ans = 1;
	return (ans);
}

//stack_aの大きさが半分になるまでstack_bにpushする関数
void	half_stack_a(t_double_stack	*head_stack)
{
	t_linked_tag	*p;
	int				size_stack_a;

	p = head_stack->stack_a->next;
	size_stack_a = head_stack->tail_a;
	while (head_stack->tail_a > size_stack_a / 2)
	{
		if (check_first_value(head_stack->stack_a, size_stack_a / 2))
		{
			pb(head_stack);
		}
		else if (!check_first_value(head_stack->stack_a, size_stack_a / 2))
			ra(head_stack, 1);
	}
}

//stack_bが分割できなくなるまでstack_aにpushする関数
void	push_until_divide(t_double_stack *head_stack)
{
	t_linked_tag	*p;
	int				pivot;

	p = head_stack->stack_a->next;
	if (head_stack->tail_b % 2 == 0)
		pivot = head_stack->tail_b / 2;
	else
		pivot = head_stack->tail_b / 2 + 1;
	while (head_stack->tail_b > pivot)
	{
		print_a_b_list(head_stack);
		if (!check_first_value(head_stack->stack_b, pivot))
		{
			pa(head_stack);
		}
		else if (check_first_value(head_stack->stack_b, pivot))
			rb(head_stack, 1);
	}
}

//sortしたstack_bをstack_aにpushしてraする関数
void	push_a_and_ra(t_double_stack *head_stack)
{
	while (head_stack->tail_b > 0)
	{
		pa(head_stack);
		ra(head_stack, 1);
	}
}

void	big_sort_main(t_double_stack *head_stack)
{
	int		b_size;
	int		sort_size;
	size_t	div_cnt;

	b_size = head_stack->tail_b;
	sort_size = 0;
	div_cnt = 0;
	half_stack_a(head_stack);
	while (head_stack->tail_b > 3)
	{
		push_until_divide(head_stack);
		div_cnt++;
	}
	run_order_thr_b(head_stack);
	push_a_and_ra(head_stack);
	printf("div_cnt = [%zu]\n", div_cnt);
}
