#ifndef PERSONAGENS_H
#define PERSONAGENS_H

typedef struct _personagem{
    char** imagem;
    int nivel;
    char* nome;
}personagem;

typedef struct _lista_p{
    struct _lista_p* prox;
    personagem p;
    struct _lista_p* ante;
}lista_p;


#endif