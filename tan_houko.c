/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tan_houko.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:40:16 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/22 15:23:11 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "push_swap.h"

//リストを作成する
t_linked_tag	*create_list(void)
{
	t_linked_tag	*head;

	head = (t_linked_tag*)malloc(sizeof(t_linked_tag));
	if (head == NULL)
	{
		printf("メモリ割り当てに失敗しました\n");
		exit(1);
	}
	head->value = 0;
	// head->tail = -1;
	head->index = -1;
	head->next = head;
	return (head);
}

//リストを削除する
void	delete_list(t_linked_tag *list)
{
	clear_list(list);
	free(list);
}

//要素を追加する
//返り値は配列のサイズ
int		add_elem(t_linked_tag	*list, int value)
{
	t_linked_tag	*tail;
	t_linked_tag	*elem;
	int				size;

	// printf("elem : 0\n");
	size = 0;
	tail = list;
	while (tail->next != list)
	{
		tail = tail->next;
		size++;
	}
	elem = (t_linked_tag*)malloc(sizeof(t_linked_tag));
	if (elem == NULL)
	{
		printf("メモリの割り当てに失敗しました\n");
		exit(1);
	}
	elem->index = size;
	elem->value = value;
	elem->next = list;
	tail->next = elem;
	return (size);
}

//全ての要素を削除する
void	clear_list(t_linked_tag *list)
{
	t_linked_tag	*p;
	t_linked_tag	*prev;

	p = list->next;
	prev = list;
	while (p != list)
	{
		prev->next = p->next;
		free(p);
		p = prev->next;
	}
}

//要素を出力する
void	print_list(t_linked_tag *list)
{
	t_linked_tag	*p;

	p = list->next;
	if (p ==list)
	{
		printf("リストは空です\n");
		return ;
	}
	while (p != list)
	{
		printf("%d\n", p->value);
		// printf("%p\n\n", p);
		// printf("index : %d\n", p->index);
		p = p->next;
	}
}

//最後の要素を探す
t_linked_tag	*search_tail(t_linked_tag *list)
{
	t_linked_tag	*p;

	p = list;
	while (p->next != list)
	{
		p = p->next;
	}
	return (p);
}

//最初の要素を削除する
int	pop_a(t_double_stack *head_stack)
{
	int				value;
	t_linked_tag	*final;
	t_linked_tag	*sta;
	int				size;

	value = 0;
	size = 0;
	value = head_stack->stack_a->next->value;
	final = search_tail(head_stack->stack_a);
	head_stack->stack_a = head_stack->stack_a->next;
	final->next = head_stack->stack_a;
	sta = head_stack->stack_a->next;
	while (sta->next != head_stack->stack_a->next)
	{
		sta->index -= 1;
		sta = sta->next;
		size++;
	}
	head_stack->tail_a = size;
	// printf("size [%d]\n", head_stack->tail_b);
	return (value);
}

int	pop_b(t_double_stack *head_stack)
{
	int				value;
	t_linked_tag	*final;
	t_linked_tag	*sta;
	int				size;

	value = 0;
	size = 0;
	value = head_stack->stack_b->next->value;
	final = search_tail(head_stack->stack_b);
	head_stack->stack_b = head_stack->stack_b->next;
	final->next = head_stack->stack_b;
	sta = head_stack->stack_b->next;
	while (sta->next != head_stack->stack_b->next)
	{
		sta->index -= 1;
		sta = sta->next;
		size++;
	}
	head_stack->tail_b = size;
	// printf("%d", head_stack->tail_b);
	return (value);
}

// int main(void)
// {
// 	t_linked_tag	*list0;

// 	list0 = create_list();
// 	add_elem(list0, 10);
// 	add_elem(list0, 110);
// 	print_list(list0);
// 	return (0);
// }
