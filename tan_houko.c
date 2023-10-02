/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tan_houko.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:40:16 by kotainou          #+#    #+#             */
/*   Updated: 2023/10/02 19:15:51 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "push_swap.h"

//リストを作成する
t_linked_tag	*create_list(void)
{
	t_linked_tag	*head;

	head = (t_linked_tag *)malloc(sizeof(t_linked_tag));
	if (head == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	head->value = 0;
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
int	add_elem(t_linked_tag	*list, int value)
{
	t_linked_tag	*tail;
	t_linked_tag	*elem;
	int				size;

	size = 0;
	tail = list;
	while (tail->next != list)
	{
		tail = tail->next;
		size++;
	}
	elem = (t_linked_tag *)malloc(sizeof(t_linked_tag));
	if (elem == NULL)
	{
		ft_printf("Error\n");
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
	if (p == list)
	{
		ft_printf("Error\n");
		return ;
	}
	while (p != list)
	{
		ft_printf("%d\n", p->value);
		p = p->next;
	}
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
