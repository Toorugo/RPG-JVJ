#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================================
// Inicializar lista
// ================================
void inicializarLista(Lista *l) {
    l->vet = NULL;
    l->tamanho = 0;
}

// ================================
// Adicionar personagem (realoca vetor)
// ================================
bool adicionarPersonagem(Lista *l, Personagem p) {
    Personagem *novo = realloc(l->vet, (l->tamanho + 1) * sizeof(Personagem));
    if (!novo) return false;

    l->vet = novo;
    l->vet[l->tamanho] = p;
    l->tamanho++;
    return true;
}

// ================================
// Remover personagem por índice
// ================================
bool removerPersonagem(Lista *l, int indice) {
    if (indice < 0 || indice >= l->tamanho) return false;

    for (int i = indice; i < l->tamanho - 1; i++) {
        l->vet[i] = l->vet[i + 1];
    }

    l->tamanho--;
    if (l->tamanho == 0) {
        free(l->vet);
        l->vet = NULL;
    } else {
        l->vet = realloc(l->vet, l->tamanho * sizeof(Personagem));
    }

    return true;
}

// ================================
// Recalcular iniciativas
// ================================
void recalcularIniciativas(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        l->vet[i].iniciativa = l->vet[i].nivel + l->vet[i].dado;
    }
}

// ================================
// Merge Sort
// ================================
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

// ================================
// Bubble Sort
// ================================
static void bubbleSort(Personagem v[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (v[j].iniciativa < v[j + 1].iniciativa) {
                Personagem tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}

// ================================
// Ordenar por iniciativa
// ================================
void ordenarPorIniciativa(Lista *l, int metodo) {
    if (l->tamanho <= 1) return;

    if (metodo == 1)
        mergeSort(l->vet, 0, l->tamanho - 1);
    else
        bubbleSort(l->vet, l->tamanho);
}

// ================================
// Exibir lista
// ================================
void exibirLista(const Lista *l) {
    printf("---- Lista de Personagens ----\n");
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d) %s  | Nivel: %d | Dado:%d | Iniciativa:%d\n",
               i, l->vet[i].nome, l->vet[i].nivel,
               l->vet[i].dado, l->vet[i].iniciativa);
    }
}

// ================================
// Destruir lista
// ================================
void destruirLista(Lista *l) {
    free(l->vet);
    l->vet = NULL;
    l->tamanho = 0;
}
