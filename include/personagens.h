#ifndef PERSONAGENS_H
#define PERSONAGENS_H

typedef struct _personagem{
    int nivel;
    char* nome;
    int dado;
    int iniciativa;
} Personagem;

typedef struct Personagem* Lista;

typedef enum{
    D4 = 4,
    D6 = 6,
    D8 = 8,
    D10 = 10,
    D12 = 12,
    D20 = 20
} Dado;

Personagem criar_personagem(char*, int, int);

int calcular_iniciativa(Personagem*);

bool verificar_dado(int);

#endif