/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:11:34 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/21 18:45:57 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ソートできているかの確認する関数
//0はソート出来ている
//1はソート出来ていない
int		is_sorted(t_double_stack *head_stack)
{
	t_linked_tag	*p;
	int				flag;
	int				now_value;
	size_t			i;

	flag = 0;
	i = 0;
	p = head_stack->stack_a->next;
	now_value = p->value;
	while (p != head_stack->stack_a && (int)i < head_stack->tail_a - 1)
	{
		if (now_value > p->next->value)
		{
			flag = 1;
		}
		p = p->next;
		now_value = p->value;
		i++;
	}
	// printf("flag = [%d]\n", flag);
	return (flag);
}