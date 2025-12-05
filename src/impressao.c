#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "impressao.h"
#include "lista.h"

#define altura 9
#define largura 60
#define AMARELO "\x1B[33m"
#define VERMELHO "\x1B[31m"
#define AZUL "\x1B[34m"
#define VERDE "\x1B[32m"
#define RESET "\x1B[0m"


void mostrar(char** m, int a){
    system("clear");
    for(int y = 0;y < a; y++){
        for(int x = 0;x < largura;x++){
                if(y < 5) printf(VERDE"\e[?25l%c"RESET, m[y][x]);
                else if(y >=15  && y <= 37) printf(AZUL"\e[?25l%c"RESET, m[y][x]);
                else if(y > 37 && y <= 50) printf(AMARELO"\e[?25l%c"RESET, m[y][x]);
                else printf(VERMELHO"\e[?25l%c"RESET, m[y][x]); 
        }
        puts("");
    }
}

me cria_menu(){
    me t;
    t.x=8;
    t.y=2;
    t.tela = (char**) malloc(altura*sizeof(char*));
    for(int a=0; a<altura; a++) t.tela[a] = (char*) malloc(largura*sizeof(char));

    for(int l=0; l<largura; l++) t.tela[0][l] = '@';

    for(int a=1; a<altura-1; a++){
        for(int l=0; l<largura; l++){
            if(l==0 || l==1) t.tela[a][l]='+';
            if(t.x==l && t.y==a) t.tela[a][l]='>';
            else t.tela[a][l] = ' ';
        }
    }

    for(int l=0; l<largura; l++) t.tela[altura-1][l] = '@';

    
    char* definir = "DEFINIR PERSONAGENS";
    for(int i=10; i<29; i++) t.tela[2][i] = definir[i-10];
    char* sair = "SAIR";
    for(int i=10; i<14; i++) t.tela[5][i] = sair[i-10];

    return t;
}

void mostra_partida(Lista* p){
    for(int l=0; l<largura; l++) printf(VERMELHO"@");
    puts("");
    for(int a=0; a<p->tamanho; a++){
        printf(AZUL"&  %s - nivel:%i - dado:%i - iniciativa:%i\n", p->vet[a].nome, p->vet[a].nivel, p->vet[a].dado, p->vet[a].iniciativa);
    }

    for(int l=0; l<largura; l++) printf(VERMELHO"@");
    puts("");
}