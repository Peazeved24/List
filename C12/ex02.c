/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:07 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/24 15:14:41 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list *ft_creat(void *data)
{
	t_list *node;
	

	// printf("TAMANHO DA MINHA STRUCT: %lu\n", sizeof(t_list));
	// printf("Quando nao sei o tamanho das coisas eu pesquiso!\n");
	// printf("int: %lu\n", sizeof(int));
	// printf("long: %lu\n", sizeof(long));
	// printf("long long: %lu\n", sizeof(long long));
	// printf("size_t: %lu\n", sizeof(size_t));
	// printf("POINTER: %lu\n", sizeof(void*));
	node = malloc(sizeof(t_list));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;

	return node;
	
}

int ft_list_size(t_list *begin_list)
{
	t_list *t;
	int i;

	i = 0;

	t = begin_list;
	while(t != NULL)
	{
		t = t->next; // quando t->next == NULL break
		i++;
	}
	return i;
}
int main()
{
	int arr[4] = {1, 3, 4, 5};
	t_list *n1, *n2, *n3;
	int a, b, c, result;
	
	a = 1;
	b = 2;
	c = 5;

	n1 = ft_creat(&a);
	n2 = ft_creat(&b);
	n3 = ft_creat(&c);
//int arr[4] = {1, 3, 4, 5, 7};

	// int *arr2 = malloc(sizeof(int) * 5);
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	result = ft_list_size(n1);
	printf("LIST_SIZE= %i\n",  result);
	t_list	*head;

	head = n1;
	while (n1)
	{	
		printf("| data field: %i |\n", *(int *)n1->data);
		printf("| next field: %p |\n", n1->next);
		// printf("\nreal address %p\n", &n1);
		printf("\nreal address %p\n", &n1->next);
		// free(n1->data);
		n1 = n1->next;
		// free(n1->next);
	}
	// printf("%i\n",  *arr);
	// printf("endereco da memoria do array: %p\n",  &arr);
	// for (int i = 0; i < 4; i++)
	// 	printf("%p\t%i\n",  &arr[i], arr[i]);
	return 0;
}