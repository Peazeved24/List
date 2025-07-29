/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:06:37 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/23 02:34:39 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
• Create the function ft_list_size, which returns the number of elements in the
list.
*/

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

int ft_list_size(t_list *begin_list)
{
    t_list *t;
    int i;

    i = 0;

    t = begin_list;
 
    while(t)
    {
        t = t->next; // entra em quartos.
        i++;
    }
    return i;
}

int main()
{
    t_list *n1, *n2, *n3;
    
    n1 = creat((int*)9);
    n2 = creat((int*)8);
    n3 = creat((int*)10);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    int count = ft_list_size(n1);
    printf("%i", count);
    return 0;
}