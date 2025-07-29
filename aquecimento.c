/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aquecimento.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:21:20 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/29 15:54:10 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

unsigned int ft_total_elem(t_list *begin)
{

    unsigned  i = 0;

    while(begin)
    {
        begin = begin->next;
        i++;
    }
    return i;
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    t_list *node;
    unsigned int total, i;

    if(!begin_list)
    {
        printf("#1");
        return NULL;
    }
    total = ft_total_elem(begin_list); // total de elementos da minha lista
    if(nbr >= total)
    {
        printf("#2"); 
        return NULL;  
    }
    i = 0;
    node = begin_list;
    while(i <  nbr)
    {
        node = node -> next;
        i++;
    }
    return node;
}

int main()
{
    t_list *n1, *n2, *n3, *t;
    unsigned int *a, *b, *c;
    
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = malloc(sizeof(int));

    if(!a || !b || !c)
        return 1;
    *a = 1;
    *b = 2;
    *c = 3;
    
    n1 = add_element(a);
    n2 = add_element(b);
    n3 = add_element(c);

    n1->next = n2;
    n2->next = n3;

    t = ft_list_at(n1, 3);
    if (t != NULL)
        printf("%d", *(unsigned int*)t->data);
    return 0;
    
}