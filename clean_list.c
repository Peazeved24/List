/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:52:03 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/26 15:51:38 by peazeved         ###   ########.fr       */
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

void  free_elements(t_list **being_list, void *value)
{
    if(being_list == NULL)
        return;
        
    t_list *node;
    
    node = *being_list;
    if((*being_list)->data == value)//
    {
        t_list *result = *being_list; // inicio da minha lista
        *being_list = (*being_list)->next; //linkagem
        free(result);
        return;
    }
    while(node->next != NULL)
    {
        if(node->next->data == value)
        {
            t_list *head = node->next;
            node->next = node->next->next;
            free(head);
            return;
        }
        node = node->next;
    }
}

int main()
{
    t_list *n1, *n2, *n3, *t;
    int i, x, z;
    
    i = 0;
    x = 3;
    z = 90;

    n1 = add_element(&i);
    n2 = add_element(&x);
    n3 = add_element(&z);

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    t = n1;
    free_fct(&t, &i);
    while(t)
    {
        printf("%d,", *(int*)t->data);
        t = t->next;
    }
    return 0;
}