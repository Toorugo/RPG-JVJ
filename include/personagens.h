#ifndef PERSONAGENS_H
#define PERSONAGENS_H
#include <stdbool.h>

typedef struct _personagem{
    int nivel;
    char* nome;
    int dado;
    int iniciativa;
} Personagem;

typedef struct {
    Personagem* personagens;
    int tamanho;
} Lista;

Personagem* criar_personagem(char*, int, int);

void calcular_iniciativas(Lista*);

bool verificar_dado(int);

void liberar_personagem(Personagem*);

#endif