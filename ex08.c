/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:56:48 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/29 16:47:04 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void *ft_list_reverse(t_list **begin_list)
{
    t_list *temp, *node;

    temp = NULL;
    node = *begin_list;
    
    while(node)
    {
        t_list *next = node->next; // guarda o caminho.
        node->next = temp;
        temp = node;
        node = next;
    }
    *begin_list = temp;
}


int main()
{

    t_list *n1, *n2, *n3;

    int *a, *b, *c;

    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = malloc(sizeof(int));
    if(!a || !b || !c)
        return 1;

    *a = 9;
    *b = 2;
    *c = 98;

    n1 = add_element(a);
    n2 = add_element(b);
    n3 = add_element(c);

    n1->next = n2;
    n2->next = n3;

    t_list *t = n1;
    ft_list_reverse(&t);
    run_list(t);
    return 0;
}