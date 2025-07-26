/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 02:25:15 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/23 02:51:39 by peazeved         ###   ########.fr       */
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

t_list *last_element(t_list *begin_list)
{
    t_list *node;
    int i = 0;

    node = begin_list;
    
    while(node->next != NULL)
        node = node->next;
    return node;
}

void ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *node, *t;

    node = add_element(data);
    t = last_element(*begin_list);
    t->next = node; // o meu proximo node recebe o meu novo data
    node->next = NULL;  // acaba;
} 

int main()
{
    t_list *n1, *n2, *n3;
    int a, b, c, i;

    a = 1;
    b = 2;
    c = 4;
    i = -000;
    
    n1 = add_element(&a);
    n2 = add_element(&b);
    n3 = add_element(&c);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    
    t_list *t = n1;
    ft_list_push_back(&n1, &i);
    while(t)
    {
        printf("%d", *(int*)t->data);
        t = t->next;
    }
    return 0;
}