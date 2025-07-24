/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:18:37 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/24 15:31:58 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"


t_list *add_element(void *data) // adicionar
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if(!node)
		return NULL;
	
	node->data = data;
	node->next = NULL;

	return node;
}

t_list *ft_list_last(t_list *begin_list)
{
	t_list *head;

	head = begin_list;

	while(head->next != NULL)
		head = head->next;
	return head;
}

// ter a cabeca
// percurrer ate ao fim.
// por a data no fim!
void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *node;

	node = ft_list_last(*begin_list);
	node->next = add_element(data); 
}
int main()
{
	t_list *n1 , *n2 , *n3, *t;
	
	int a, b, c;

	a = 1;
	b = 2;
	c = 4; 
	int d = 90;
	
	n1 = add_element(&a);
	n2 = add_element(&b);
	n3 = add_element(&c);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	
	ft_list_push_back(&n1, &d);

	t = n1;
	while(t)
	{
		printf("%i,", *(int*)t->data);
		t = t->next;
	}
	
	return 0;
}