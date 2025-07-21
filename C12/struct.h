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

#endif