#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializarLista(Lista *l) {
    l->vet = NULL;
    l->tamanho = 0;
}


bool adicionarPersonagem(Lista *l, Personagem p) {
    Personagem *novo = realloc(l->vet, (l->tamanho + 1) * sizeof(Personagem));
    if (!novo) return false;
    l->vet = novo;
    l->vet[l->tamanho++] = p;
    return true;
}


bool removerPersonagem(Lista *l, int indice) {
    if (indice < 0 || indice >= l->tamanho) return false;

    for (int i = indice; i < l->tamanho - 1; i++)
        l->vet[i] = l->vet[i + 1];

    l->tamanho--;
    if (l->tamanho == 0) {
        free(l->vet);
        l->vet = NULL;
    } else {
        l->vet = realloc(l->vet, l->tamanho * sizeof(Personagem));
    }
    return true;
}

void recalcularIniciativas(Lista *l) {
    for (int i = 0; i < l->tamanho; i++)
        l->vet[i].iniciativa = l->vet[i].nivel + l->vet[i].dado;
}


static void merge(Personagem v[], int inicio, int meio, int fim) {
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;

    Personagem *E = malloc(tam1 * sizeof(Personagem));
    Personagem *D = malloc(tam2 * sizeof(Personagem));

    for (int i = 0; i < tam1; i++) E[i] = v[inicio + i];
    for (int j = 0; j < tam2; j++) D[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < tam1 && j < tam2) {
        if (E[i].iniciativa >= D[j].iniciativa)
            v[k++] = E[i++];
        else
            v[k++] = D[j++];
    }

    while (i < tam1) v[k++] = E[i++];
    while (j < tam2) v[k++] = D[j++];

    free(E);
    free(D);
}

static void mergeSort(Personagem v[], int inicio, int fim) {
    if (inicio >= fim) return;

    int meio = (inicio + fim) / 2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);
    merge(v, inicio, meio, fim);
}

static void insertionSort(Personagem v[], int n) {
    for (int i = 1; i < n; i++) {
        Personagem chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].iniciativa < chave.iniciativa) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void ordenarPorIniciativa(Lista *l) {
    if (l->tamanho <= 1) return;


    const int LIMITE = 10;

    if (l->tamanho <= LIMITE) {
        insertionSort(l->vet, l->tamanho);
    } else {
        mergeSort(l->vet, 0, l->tamanho - 1);
    }
}


void destruirLista(Lista *l) {
    free(l->vet);
    l->vet = NULL;
    l->tamanho = 0;
}
