/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:26:45 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/24 15:14:38 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list *creat(void *data) // criar nodes
{
    t_list *node;  // inicializar o node.

    node = malloc(sizeof(t_list)); //cria um node;
    if(!node)
        return NULL;
    
    node->data = data; // segua um valor 
    node->next = NULL; // aponta para NULL;

    return node;
}


void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *node; // node (alocar espaco para um novo node)
    node = creat(data); // crio o node com  a data.
    
    node->next = *begin_list; // o meu proximo node sera o primeiro node.
    *begin_list = node; // o meu primmeiro node recebe o novo node.
}

int main()
{
    t_list *n1, *n2, *n3, *t; // vou (em prencipio) precisar de X nodes.

    int a = 1, b = 2, c = 3;
    int val = 9;
    int *v = &val;

    n1 = creat(&a);
    n2 = creat(&b);
    n3 = creat(&c);

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    ft_list_push_front(&n1, v);
    t = n1;
    while(t)
    {
        printf("%d,",*(int*)t->data);
        t = t->next ;
    }
    return 0;
}