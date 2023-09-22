/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minizer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:39:17 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 16:25:29 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_loaf_array(t_double_stack *head_stack, int *thr_stack)
{
	t_linked_tag	*p;
	int				i;

	i = 0;
	p = head_stack->stack_a->next;
	printf("sett ");
	while (p != head_stack->stack_a)
	{
		p->value = thr_stack[i];
		printf("%d ", p->value);
		i++;
		p = p->next;
	}
	free(thr_stack);
	printf("\n");
}

void	two_to_thr(t_double_stack *head_stack, int *one_stack, int *two_stack)
{
	int		*thr_stack;
	int		i;
	int		j;

	thr_stack = ft_calloc(sizeof(int *), (head_stack->tail_a + 1));
	i = 0;
	while (i < head_stack->tail_a)
	{
		j = 0;
		while (j < head_stack->tail_a)
		{
			if (one_stack[i] == two_stack[j])
			{
				// printf("%d ", two_stack[j]);
				thr_stack[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(one_stack);
	free(two_stack);
	stack_a_loaf_array(head_stack, thr_stack);
}

//重複の処理もするところ
void	bubble_sort(t_double_stack *head_stack, int *one_stack)
{
	int		*two_stack;
	int		i;
	int		j;
	int		tmp;

	two_stack = ft_calloc(sizeof(int *), (head_stack->tail_a + 1));
	ft_memcpy(two_stack, one_stack, sizeof(int *) * head_stack->tail_a);
	i = 0;
	while (i < head_stack->tail_a)
	{
		j = i + 1;
		while (j < head_stack->tail_a)
		{
			if (two_stack[i] > two_stack[j])
			{
				tmp = two_stack[i];
				two_stack[i] = two_stack[j];
				two_stack[j] = tmp;
			}
			else if (two_stack[i] == two_stack[j])
				exit(1);
			j++;
		}
		i++;
	}
	two_to_thr(head_stack, one_stack, two_stack);
}

void	minizer_stack(t_double_stack *head_stack)
{
	t_linked_tag	*p;
	size_t			i;
	int				*one_stack;

	one_stack = ft_calloc(sizeof(int *), (head_stack->tail_a + 1));
	p = head_stack->stack_a->next;
	i = 0;
	while (p != head_stack->stack_a)
	{
		one_stack[i] = p->value;
		p = p->next;
		i++;
	}
	i = 0;
	bubble_sort(head_stack, one_stack);
}
