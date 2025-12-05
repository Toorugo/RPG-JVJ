#include "menu.h"
#include "lista.h"
#include "personagens.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
# include "utils.h"

Lista* leitor_arquivo(char* caminho) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    FILE* arquivo = fopen(caminho, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo\n");
        return NULL;
    }

    char linha[1024];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';

        char* personagem = strtok(linha, ";");
        while (personagem != NULL) {

            while (*personagem == ' ') personagem++;


            char* nome = strtok(personagem, ",");
            char* str_nivel = strtok(NULL, ",");
            char* str_dado = strtok(NULL, ",");

            int nivel = atoi(str_nivel);
            int dado = atoi(str_dado);

            Personagem* p = criar_personagem(nome, nivel, dado);
            if (p != NULL) {
                adicionarPersonagem(lista, *p);
                free(p);
            }

            personagem = strtok(NULL, ";");
        }
    }

    fclose(arquivo);
    return lista;
}

Lista* criar_bonecos(){
    system("clear");
    puts("Digite o endereço do arquivo .txt com os personagens");
    char endereco[100];
    scanf("%99s", endereco);
    return leitor_arquivo(endereco);
}

Lista* menu(int* resposta){
    me tela = cria_menu();
    while(true){
        mostrar(tela.tela, 20);

        char entrada = getch();

        if(entrada == 'm' || entrada== 'M'){

            if(tela.y == 7) tela.y = tela.y+3;
            else tela.y = tela.y-3;
        }

        else if(entrada == 'c' || entrada == 'C'){

            if(tela.y==7) return criar_bonecos();
            else {
                *resposta = 0;
                return NULL;
            }
        }
    }
}
