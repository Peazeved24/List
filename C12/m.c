/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:03:49 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/21 16:18:52 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int ft_atoi(char *str) // passar os argumentos
{
    int n;
    int s;

    n = 0;
    s = 1;

    while(*str == ' ' || *str == '\n')
        str++;
    if(*str == '+' || *str == '-')
    {
        if(*str == '-')
            s = -1;
        else
            return 0;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        n = n * 10 + (*str - '0');
        str++;
    }
    return (n * s);    
}

t_list *creat(void *data) // criar nodes
{
    t_list *node;

    node = malloc(sizeof(t_list)); //cria um node;
    if(!node)
        return NULL;
    node->data = data;
    node->next = NULL;

    return node;
}


int main(int ac, char **av)
{
    t_list *n1, *n2, *n3, *t;
    if(ac == 4)
    {
        int a, b, c;

        a = ft_atoi(av[1]);
        b = ft_atoi(av[2]);
        c = ft_atoi(av[3]); 

        n1 = creat(&a);
        n2 = creat(&b);
        n3 = creat(&c);

        n1->next = n2;
        n2 ->next = n3;
        n3->next = NULL;

        t = n1;
        while(t)
        {
            printf("%d,", *(int*)t->data);
            t= t->next;
        }
        free(n1);
        free(n2);
        free(n3);
    }
    return 0;
}
