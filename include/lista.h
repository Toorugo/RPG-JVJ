#ifndef LISTA_H
#define LISTA_H
#include "personagens.h"

typedef struct {
    Personagem *vet;
    int tamanho;
    int capacidade;
} Lista;

void inicializarLista(Lista *l);
void adicionarPersonagem(Lista *l);
void removerPersonagem(Lista *l);
void recalcularIniciativas(Lista *l);

void mergeSort(Personagem v[], int inicio, int fim);
void quickSort(Personagem v[], int inicio, int fim);
void ordenarPorIniciativa(Lista *l, int metodo);

void exibirLista(Lista *l);

void destruirLista(Lista *l);


#endif
