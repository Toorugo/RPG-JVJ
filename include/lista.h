#ifndef LISTA_H
#define LISTA_H
#include "personagens.h"

typedef struct {
    Personagem *vet;
    int tamanho;

} Lista;

void inicializarLista(Lista *l);
bool adicionarPersonagem(Lista *l, Personagem p);
bool removerPersonagem(Lista *l, int indice);
void recalcularIniciativas(Lista *l);

void mergeSort(Personagem v[], int inicio, int fim);
void insertionSort(Personagem v[], int n);
void ordenarPorIniciativa(Lista *l);

void destruirLista(Lista *l);

#endif
