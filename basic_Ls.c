/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_Ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:18:02 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/17 17:53:53 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

/*typedef struct Node{
	int x; // valor armazenado dentro do meu  node.
	struct Node *next; // ref do proximo valor / NULL.
}Node;*/ // alias

/*
int main(int ac, char **av)
{
	Node a, b, c, *current; // os meus nodes + root.(current e a)

	a.x = 1; // valor inicial do meu node 
	a.next = &b; // proximo valor

	b.x = 2; // valor secundarii
	b.next =  &c; // proximo valor 

	c.x = 3; // etc
	c.next = NULL; // o fim da minha lista.

	current = &a; // contem a referencia da minha root.
	while(current) // enquanto n for NULL.
	{
		printf("%d.", current->x); // -> acessa o proximo valor (x) dentro da minha lista
		current = current->next; // acessa o meu proximo valor ("""incremento""" (current++))
	}
	return 0;
}*/

int ft_atoi(char *str)
{
	int s;
	int n;

	s = 1;
	n = 0;

	while(*str == ' ' || *str == '\n')
		str++;
	if(*str == '+' || *str == '-')
	{
		if(*str == '-')
			s = -1;
		else
			return 0;
			str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * s);
}

int main(int ac, char **av)
{
	Node a, b, c, *current;

	a.x = ft_atoi(av[1]);
	a.next = &b;

	b.x = ft_atoi(av[2]);
	b.next = &c;

	c.x = ft_atoi(av[3]);
	c.next = NULL;

	current = &a;

	while(current)
	{
		printf("%i,", current -> x);
		current = current -> next;
	}
	return 0;
}