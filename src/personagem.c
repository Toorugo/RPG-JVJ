# include <stdio.h>
# include "personagens.h"
# include <stdlib.h>

Personagem criar_personagem(char* nome, int nivel, int dado){
    Personagem p;

    if(nivel < 1 || nivel > 20){
        printf("Nível inválido (Deve ser entre 1 e 20)\n");
        return NULL;
    }

    p.nivel = nivel;

    if(!verificar_dado(dado)){
        printf("Dado inválido (Deve ser 4, 6, 8, 10, 12 ou 20)\n");
        return NULL;
    }

    p.dado = dado;
    p.iniciativa = nivel + dado;
    p.nome = nome;
    return p;
}

int calcular_iniciativa(Personagem* p){
    p->iniciativa = p-nivel + (rand() % p->dado) + 1;
    return p->iniciativa;
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