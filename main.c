/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:52 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 17:21:07 by kotainou         ###   ########.fr       */
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
	if (ac == 3)
	{
		stack_a = create_list();
		head_stack->stack_a = stack_a;
		add_elem(stack_a, ft_atoi(av[1]));
		add_elem(stack_a, ft_atoi(av[2]));
		print_list(head_stack->stack_a);
		ra(head_stack);
	}
	else
	{
		i = 1;
		stack_a = create_list();
		head_stack->stack_a = stack_a;
		stack_b = create_list();
		head_stack->stack_b = stack_b;
		while ((int)i < ac)
		{
			head_stack->tail_a = add_elem(stack_a, ft_atoi(av[i]));
			head_stack->tail_b = add_elem(stack_b, ft_atoi(av[i]));
			i++;
		}
		head_stack->tail_a = ac - 1;
		print_list(head_stack->stack_a);
		minizer_stack(head_stack);
		run_order_thr(head_stack);
		ft_printf("\n");
		// ra(head_stack);
		// rra(head_stack);
		// pb(head_stack);
		// sa(head_stack);
		// rb(head_stack);
		// rrb(head_stack);
		// printf("find = [%d]\n", find_number(head_stack, 3 - 1));
		printf("list a\n");
		print_list(head_stack->stack_a);
		// printf("list b\n");
		// print_list(head_stack->stack_b);
	}
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }