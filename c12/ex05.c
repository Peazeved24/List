/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 02:52:49 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/23 16:50:11 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list *add_elemt(void *data)
{
   t_list *node;
   
   node = malloc(sizeof(t_list));
   node->data = data;
   node->next = NULL;
   
   return node;
}

t_list *ft_list_push_strs(int size, char **strs)
{
    t_list *temp, *node;
    int i;

    i  = 0;
    if(!strs || size <= 0)
        return NULL;
    
    temp = NULL;
    while(i < size)
    {
        node = add_elemt((void*)strs[i]);
        node->next = temp;
        temp = node;
        i++;
    }
    return node;
}
 
int main()
{
    t_list *result;
    
    char *str[3] = {"ze" , "da", "manga"};
    result = ft_list_push_strs(3, &str[0]);
    while(result)
    {
        printf("%s-", (char*)result->data);
        result = result->next;
    }
    free(result);
    return 0;
}