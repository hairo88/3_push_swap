/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tan_houko.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:40:16 by kotainou          #+#    #+#             */
/*   Updated: 2023/09/13 17:18:23 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "push_swap.h"

t_linked_tag	*search_tail(t_linked_tag *list);
void	print_list(t_linked_tag *list);
void	clear_list(t_linked_tag *list);
void	add_elem(t_linked_tag	*list, int value);
void	delete_list(t_linked_tag *list);


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
void	add_elem(t_linked_tag	*list, int value)
{
	t_linked_tag	*tail;
	t_linked_tag	*elem;

	// printf("elem : 0\n");
	tail = search_tail(list);
	elem = (t_linked_tag*)malloc(sizeof(t_linked_tag));
	if (elem == NULL)
	{
		printf("メモリの割り当てに失敗しました\n");
		exit(1);
	}
	elem->value = value;
	elem->next = list;
	tail->next = elem;
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
t_linked_tag	*pop(t_linked_tag *list, t_double_stack *head_stack)
{
	list
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
