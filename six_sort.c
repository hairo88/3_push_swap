/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:48:15 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 18:10:35 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	six_sort_main(t_double_stack *head_stack)
{
	int	min_value;

	min_value = 0;
	while (head_stack->tail_a > 3)
	{
		if (find_number(head_stack, min_value) == 0)
		{
			min_value++;
			pb(head_stack);
		}
		ra(head_stack);
	}
	run_order_thr(head_stack);
}