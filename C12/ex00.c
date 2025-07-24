/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:25:53 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/22 15:38:38 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list *ft_create_elem(void *data) // nesta parte e feita a atribuicao de valores
{
    t_list *node; // criar um elemento

    node = malloc(sizeof(t_list)); // criar 1 bloco de memoria (node)
    if(!node)
        return NULL;
        
    node->data = data;
    node->next = NULL;
    return (node);
}


int main() // stack
{
    t_list *a, *b, *c, *t; // criar ptr que apontar para os meus nodes.
    int x , y, z; // valores

    x = 1; // valores
    y = 2;
    z = 3;

    a  = ft_create_elem(&x); // associacoes a = x;
    b  = ft_create_elem(&y);
    c  = ft_create_elem(&z);

    a->next = b; // processo de linkagem
    b->next = c;
    c->next = NULL;
    
    t = a; //inicio da minha lista
    while(t) 
    {
        printf("%d,", *(int*)t->data);
        t = t -> next;
    }
    return 0;
}