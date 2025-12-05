#include "partida.h"
#include <stdlib.h>
#include <stdio.h>
# include "utils.h"

void partida(Lista* lista, int* resp){
    while(*resp != 2){
        recalcularIniciativas(lista);
        ordenarPorIniciativa(lista);
        mostra_partida(lista);
        printf("Digite:\n1 - adicionar personagem\n2 - remover personagem\n3 - avançar para o proximo turno\n 4 - encerrar o combate\n");
        char r = getch();
        switch (r)
        {
        case '1':
            system("clear");
            puts("Digite o nome, nivel e dado");
            char* nome;
            int nivel, dado;
            scanf("%s", nome );
            scanf("%i", &nivel );
            scanf("%i", &dado );
            Personagem* p = criar_personagem(nome, nivel, dado);
            adicionarPersonagem(lista, *p);
            break;
        case '2':
            puts("Digite quem quer excluir:\n");
            int indice;
            scanf("%i", &indice);
            removerPersonagem(lista, indice);
            break;
        case '3':
            break;
        case '4':
            *resp = 2;
            break;
        
        default:
            puts("Valor não válido");
            break;
        }
    }

}