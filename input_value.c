/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:08:30 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:02:25 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//文字かどうか判断している
int	is_char_input(char *value)
{
	size_t	i;
	size_t	num;
	int		flag;

	i = 0;
	flag = 0;
	num = ft_strlen(value);
	while (i < num)
	{
		if (!ft_isdigit(value[i]) && value[i] != '-')
		{
			flag = 1;
			printf("isdigit = %c\nrnt == [%d]\n", value[i], ft_isdigit(value[i]));
		}
		i++;
	}
	return (flag);
}

//ソート済みかどうか？
//0はソート済　１は未ソート
int	is_sort(t_double_stack *head_stack)
{
	t_linked_tag	*p;
	size_t			i;
	int				*array;
	int				flag;

	i = 0;
	flag = 1;
	p = head_stack->stack_a->next;
	array = ft_calloc(sizeof(int *), (head_stack->tail_a + 1));
	while (p != head_stack->stack_a)
	{
		array[i] = p->value;
		p = p->next;
		i++;
	}
	i = 0;
	while ((int)i < head_stack->tail_a - 1)
	{
		if (array[i] > array[i + 1])
			flag = 0;
		i++;
	}
	free(array);
	return (flag);
}

void	input_value_digit(t_double_stack *head_stack, int ac, char *av[])
{
	size_t	i;

	i = 1;
	while ((int)i < ac)
	{
		add_elem(head_stack->stack_a, ft_atoi(av[i]));
		i++;
	}
}

int	input_value(t_double_stack *head_stack, int ac, char *av[])
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
		head_stack->tail_a = num;
		while ((int)i < num)
		{
			if (is_char_input(data_value[i]))
			{
				ft_printf("Error\n");
				exit(1);
			}
			add_elem(stack_a, ft_atoi(data_value[i]));
			i++;
		}
	}
	return (1);
}

void	input_value_main(t_double_stack *head_stack, int ac, char *av[])
{
	int		flag_av;

	flag_av = 0;
	if (ac == 2)
		flag_av = input_value(head_stack, ac, av);
	else
		input_value_digit(head_stack, ac, av);
	if (ac != 1 && is_sort(head_stack))
	{
		exit(0);
	}
}

// -1978451668
// -1958419719
//  156864768
//  235498006
//  723222320