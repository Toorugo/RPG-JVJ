#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void leitor_arquivo(char* caminho) {
   FILE* arquivo = fopen(caminho, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        return;
    }

    char linha[1024];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';

        char* personagem = strtok(linha, ";");
        while (personagem != NULL) {

            while (*personagem == ' ') personagem++;


            char* nome = strtok(conjunto, ",");
            char* nivel = strtok(NULL, ",");
            char* dado = strtok(NULL, ",");

            int nivel = atoi(nivel);
            int dado = atoi(dado);



            conjunto = strtok(NULL, ";");
        }
    }

    fclose(arquivo);
}


