#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(Lista *l) {
    l->tamanho = 0;
    l->capacidade = 2;
    l->vet = (Personagem*) malloc(l->capacidade * sizeof(Personagem));
}

void aumentarCapacidade(Lista *l) {
    l->capacidade *= 2;
    l->vet = (Personagem*) realloc(l->vet, l->capacidade * sizeof(Personagem));
}

void adicionarPersonagem(Lista *l) {
    if (l->tamanho == l->capacidade) {
        aumentarCapacidade(l);
    }

    Personagem p;

    printf("Nome: ");
    scanf("%s", p.nome);

    printf("Nivel (1 a 20): ");
    scanf("%d", &p.nivel);

    printf("Dado (4,6,8,10,12,20): d");
    scanf("%d", &p.dado);

    p.iniciativa = 0;

    l->vet[l->tamanho++] = p;
}

void removerPersonagem(Lista *l) {
    if (l->tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }

    int pos;
    printf("Posição para remover (0 a %d): ", l->tamanho - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= l->tamanho) {
        printf("Posição inválida!\n");
        return;
    }

    for (int i = pos; i < l->tamanho - 1; i++) {
        l->vet[i] = l->vet[i + 1];
    }

    l->tamanho--;
}

void recalcularIniciativas(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        int roll = (rand() % l->vet[i].dado) + 1;
        l->vet[i].iniciativa = l->vet[i].nivel + roll;
