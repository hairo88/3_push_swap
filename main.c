/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:52 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 20:17:50 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_linked_tag	*stack_a;
	t_linked_tag	*stack_b;
	t_double_stack	*head_stack;
	size_t			i;
	int		pop_value;

	head_stack = NULL;
	pop_value = 0;
	head_stack = (t_double_stack *)malloc(sizeof(t_double_stack));
	ft_memset(head_stack, 0, 2);
	stack_a = create_list();
	head_stack->stack_a = stack_a;
	stack_b = create_list();
	head_stack->stack_b = stack_b;
	if (ac == 2)
	{
		input_value(head_stack, ac ,av);
	}
	else if (ac == 3)
	{
		add_elem(stack_a, ft_atoi(av[1]));
		add_elem(stack_a, ft_atoi(av[2]));
	}
	else if (3 < ac)
	{
		i = 1;
		while ((int)i < ac)
		{
			add_elem(stack_a, ft_atoi(av[i]));
			// head_stack->tail_b = add_elem(stack_b, ft_atoi(av[i]));
			i++;
		}
		head_stack->tail_a = ac - 1;
		head_stack->tail_b = 0;
		// print_list(head_stack->stack_a);
		// printf("head->stack->stail_a[%d]\n", head_stack->tail_a);
		// pb(head_stack);
		// ft_printf("\n");
		// printf("list a\n");
		// print_list(head_stack->stack_a);
		// printf("list b\n");
		// print_list(head_stack->stack_b);
	}
	minizer_stack(head_stack);
	// run_order_thr(head_stack);
	// six_sort_main(head_stack);
	print_list(head_stack->stack_a);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }