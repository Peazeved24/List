/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                    +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:0:20 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/23 01:50:31 by peazeved         ###   ########.fr       */
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

t_list *ft_list_last(t_list *begin_list)
{
    t_list *node;

    node = begin_list;

    while(node->next != NULL)
        node= node->next;
    return node;
}

int main()
{
    t_list *n1, *n2 , *n3, *t;
    int a, b, c;

    a = 4;
    b = 5;
    c = 9;
    
    n1 = add_element(&a);
    n2 = add_element(&b);
    n3 = add_element(&c);

    n1->next = n2;
    n2->next = n3;
    
    t = ft_list_last(n1);

    printf("%d", *(int*)t->data);
    return 0;
}