#ifndef IMPRESSAO_H
#define IMPRESSAO_H

#include "lista.h"

typedef struct _menu{
    char** tela;
    int x;
    int y;
} me;

void mostrar(char** m , int a);
me cria_menu();
void mostra_partida(Lista* p );

#endif