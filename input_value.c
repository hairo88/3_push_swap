/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:08:30 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 20:06:23 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input_value(char *value)
{
	size_t	i;
	size_t	num;
	int		flag;

	i = 0;
	flag = 0;
	num = ft_strlen(value);
	while (i < num)
	{
		if (!ft_isdigit(value[i]))
			flag = 1;
		i++;
	}
	return (flag);
}

void	input_value(t_double_stack *head_stack, int ac, char *av[])
{
	t_linked_tag	*stack_a;
	char			**data_value;
	size_t			i;
	int				num;

	i = 0;
	num = 0;
	stack_a = head_stack->stack_a;
	if (ac == 2)
	{
		data_value = ft_split(av[1], ' ', &num);
		while ((int)i < num)
		{
			if (check_input_value(data_value[i]))
			{
				ft_printf("Error\n");
				exit(1);
			}
			add_elem(stack_a, ft_atoi(data_value[i]));
			i++;
		}
	}
	else if (ac == 3)
	{
		add_elem(stack_a, ft_atoi(av[1]));
		add_elem(stack_a, ft_atoi(av[2]));
		// print_list(head_stack->stack_a);
	}
	// print_list(head_stack->stack_a);
}