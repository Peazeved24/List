/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:38:22 by peazeved          #+#    #+#             */
/*   Updated: 2025/07/26 16:10:45 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void free_fct(void *data) // funcao so limpa
{
    free(data);
}

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *head; // ptr que aponta para o inicio da minha lista
    
    head = begin_list;
    while(head) // n for nullo
    {
        head = begin_list->next; // salva m eo segundo elemento;
        if(free_fct) // condicao -- para ver se os meus dados.
        {
            free_fct(begin_list->data); // apaguei o primeiro node;
            printf("#");
        }
        free(begin_list); // libertar espaco para associar ao meu proximo.
        begin_list = head;
    }
}

int main()
{
    t_list *n1, *n2, *n3;
    int *a, *b, *c;
    
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = malloc(sizeof(int));

    if(!a | !b | !b)
        return 1;
    *a = 1;
    *b = 2;
    *c = 3;
    
    n1 = add_element(a);
    n2 = add_element(b);
    n3 = add_element(c);

    n1->next = n2;
    n2->next = n3;

    ft_list_clear(n1, free_fct);    
    return 0;
}