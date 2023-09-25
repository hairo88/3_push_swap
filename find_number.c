/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:18:25 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/24 17:26:39 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_number(t_double_stack *head_stack, int number)
{
	t_linked_tag	*list;
	int				i;
	int				ret_number;

	list = head_stack->stack_a->next;
	i = 0;
	ret_number = -1;
	while (list != head_stack->stack_a)
	{
		// printf("search = [%d] ", list->value);
		if (number == list->value)
			ret_number = i;
		i++;
		list = list->next;
	}
	return (ret_number);
}
