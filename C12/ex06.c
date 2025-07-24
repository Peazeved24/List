/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:03:14 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/24 21:01:39 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list *add_element(void *data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if(!node)
		return NULL;
	
	node->data = data;
	node->next = NULL;

	return node; 
}

void free_fct(t_list **head, void *data) // apaga os elementos
{
	if(*head == NULL) // seguranca
		return; 
	t_list *node;

	node = *head;

	while(node->next != NULL) //
	{
		if(node->next->data == data) // se o meu proximo valor for igual a data.
		{
			t_list *remove = node->next; // "aim" ao meu node
			node->next = node->next->next; // pula e troca pelo o proximo
			free(remove); // remove
		}
		node = node->next; // avanca
	}
}

/*
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *temp;

	temp = begin_list;
	
	while(temp->next) // enquanto n for nullo
	{
		free_fct(temp->data);
	}
}*/

int main()
{
	t_list *n1, *n2, *n3, *t;
	int a, b ,c;

	a = 1;
	b = 2;
	c = 3;

	n1 = add_element(&a);
	n2 = add_element(&b);
	n3 = afree_fct(&t, &c);dd_element(&c);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	
	t = n1;
	free_fct(&t, &b);
	while(t)
	{
		printf("%d,", *(int*)t->data);
		t = t->next;
	}
	return 0;
}