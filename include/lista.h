#ifndef LISTA_H
#define LISTA_H
#include "personagens.h"

typedef struct {
    Personagem *vet;
    int tamanho;

} Lista;

void inicializarLista(Lista *l);
void adicionarPersonagem(Lista *l, Personagem p);
void removerPersonagem(Lista *l, int indice);
void recalcularIniciativas(Lista *l);

void mergeSort(Personagem v[], int inicio, int fim);
void quickSort(Personagem v[], int inicio, int fim);
void ordenarPorIniciativa(Lista *l, int metodo);

void exibirLista(Lista *l);
void destruirLista(Lista *l);

#endif
