#ifndef IMPRESSAO_H
#define IMPRESSAO_H

typedef struct _menu{
    char** tela;
    int x;
    int y;
} me;

void mostrar(char** , int);
me cria_menu();
void mostra_partida(Lista );

#endif