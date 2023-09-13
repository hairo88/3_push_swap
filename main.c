/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:52 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/13 16:30:13 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	compare_values(int	a, int b)
// {
	
// }

int	main(int ac, char *av[])
{
	t_linked_tag	*stack_a;
	// t_linked_tag	*stack_b;
	t_double_stack	*head_stack;
	size_t			i;

	head_stack = NULL;
	ft_memset(head_stack, 0, 2);
	if (ac == 3)
	{
		stack_a = create_list();
		add_elem(stack_a, ft_atoi(av[1]));
		add_elem(stack_a, ft_atoi(av[2]));
		// printf("stack_a->value = [%d]\n", stack_a->value);
		// printf("stack_a = [%p]\n", stack_a);
		ra(stack_a, head_stack);
	}
	else
	{
		i = 1;
		stack_a = create_list();
		head_stack = malloc(sizeof(t_double_stack));
		head_stack->stack_a = stack_a;
		while ((int)i < ac)
		{
			// printf("av[%zu]=[%d]\n", i, ft_atoi(av[i]));
			add_elem(stack_a, ft_atoi(av[i]));
			i++;
		}
		// printf("%d", ft_atoi(av[1]));
		ra(stack_a, head_stack);
	}
	printf("stack_a list\n");
	print_list(stack_a);
	printf("ok\n");
	// printf("ac = [%d]\n", ac);
	// printf("%s\n", av[1]);
}
