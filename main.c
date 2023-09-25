/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:52 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/25 17:00:11 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_stack	*init_head_stack(int ac)
{
	t_double_stack	*head_stack;
	t_linked_tag	*stack_a;
	t_linked_tag	*stack_b;

	head_stack = (t_double_stack *)malloc(sizeof(t_double_stack));
	if (head_stack == NULL)
	{
		ft_printf("割り当てに失敗しました\n");
		exit(1);
	}
	ft_memset(head_stack, 0, sizeof(t_double_stack));
	stack_a = create_list();
	stack_b = create_list();
	head_stack->stack_a = stack_a;
	head_stack->stack_b = stack_b;
	head_stack->tail_a = ac - 1;
	head_stack->tail_b = 0;
	return (head_stack);
}

int	main(int ac, char *av[])
{
	t_double_stack	*head_stack;

	head_stack = init_head_stack(ac);
	input_value_main(head_stack, ac, av);
	minizer_stack(head_stack);
	run_order_two(head_stack);
	run_order_thr(head_stack);
	run_order_six(head_stack);
	
	// print_list(head_stack->stack_a);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }