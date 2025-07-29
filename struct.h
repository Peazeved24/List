#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_list 
{
    struct s_list *next; // o ptr para o proximo node
    void *data; // minha var que recebe valores. ptr generico -
} t_list;


void *run_list(t_list *being_list)
{
    t_list *t;

    t = being_list;

    while(t)
    {
        printf("%d,", *(int*)t->data);
        t = t->next;
    }
}

t_list *add_element(void *data)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if(!node)
        return NULL;
    
    node->data = data;
    node->next = NULL; // null

    return node;
}


#endif