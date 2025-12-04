# include <stdio.h>
# include "personagens.h"
# include <stdlib.h>
# include <stdbool.h>

Personagem* criar_personagem(char* nome, int nivel, int dado){

    if(nivel < 1 || nivel > 20){
        printf("Nível inválido (Deve ser entre 1 e 20)\n");
        return NULL;
    }

    if(!verificar_dado(dado)){
        printf("Dado inválido (Deve ser 4, 6, 8, 10, 12 ou 20)\n");
        return NULL;
    }
    Personagem* p = (Personagem*) malloc (sizeof(Personagem));
    if (!p){
        printf("Erro ao alocar memória para o personagem\n");
        return NULL;
    }
    p->nivel = nivel;
    p->dado = dado;
    p->iniciativa = nivel + dado;
    p->nome = malloc(strlen(nome) + 1);
    if (!p->nome){
        printf("Erro ao alocar memória para o nome do personagem\n");
        free(p);
        return NULL;
    }
    strcpy(p->nome, nome);

    return p;
}

void calcular_iniciativas(Lista* pont){
    if (pont->tamanho == 0) return;
    if(!pont || !pont->personagens) return;
    for (int i = 0; i < pont->tamanho; i++){
        pont->personagens[i].iniciativa= pont->personagens[i].nivel + (rand() % pont->personagens[i].dado) + 1;
    }
}

bool verificar_dado(int dado){
    switch(dado){
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
        case 20:
            return true;
        default:
            return false;
    }
}

void liberar_personagem(Personagem* p){
    if (p) {
        free(p->nome);
        free(p);
    }
}

void liberar_lista(Lista* lista) {
    if (lista) {
        free(lista->personagens);
        free(lista);
    }
}