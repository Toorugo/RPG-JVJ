#ifndef IMPRESSAO_H
#define IMPRESSAO_H

typedef struct _menu{
    char** tela;
    int x;
    int y;
} me;

void mostrar(char** );
void renderizar_menu(me );
void renderizar_partida(int* );

#endif