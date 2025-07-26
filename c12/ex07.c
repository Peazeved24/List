/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:11:11 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/26 16:33:12 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    t_list *node;
    unsigned int i;
    
    i = 0;
    node = begin_list;

    while(i++ < nbr) //numero de voltas
    {
        if(!node)
            return NULL;
        node = node->next; // atualiza o meu node tendo em consideracao o numero de voltas
    }
    return node;
}   


int main()
{
    t_list *n1, *n2, *n3, *t;

    int *a, *b, *c;
    
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = malloc(sizeof(int));

    if(!a ||  !b || !c)
        return 1;
    
    *a = 10;
    *b = 2;
    *c = 90;

    n1 = add_element(a);
    n2 = add_element(b);
    n3 = add_element(c);

    n1->next =n2;
    n2->next =n3;
    
   t =  ft_list_at(n1, 1);

    run_list(t);
    return 0;
}