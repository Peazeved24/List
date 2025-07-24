/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:51:18 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/24 18:39:39 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
/*
	a funcao pede para que eu crie um elemento para cada str dentro do meu array 
	o meu primeiro sera o meu ultimo.
	strs serao a minha data(?)
*/

t_list *add_element(void *data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if(!node)
		return NULL;
	 
	node->data = strdup(data);
	node->next = NULL;

	return node;
}

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list *node, *temp; 
	

	temp = NULL;
	int i;

	i = 0;
	while(i < size)
	{
		node = add_element(strs[i]); // pega o primeiro
		node->next = temp;
		temp = node; // re
		i++;
	}
	return temp;
}
 
int main()
{
	t_list *result; 
	char *str[5] = {"ze", "da", "manga", "ola", "mundo"};
	
	result =  ft_list_push_strs(5, &str[0]);
	while(result) //percorre sempre a lista.
	{
		t_list *head = result; // salvar a minha cabeca
		printf("%s,", (char*)result->data);
		result = result->next;
		free(head);
	}
	return 0;
}