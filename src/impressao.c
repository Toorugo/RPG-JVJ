#include "impressao.h"
#define altura 20
#define largura 20

void mostrarj(char** m){
    system("clear");
    for(int y = 0;y < altura; y++){
        for(int x = 0;x < largura;x++){
                printf("\x1B[33m\e[?25l%c", m[y][x]);
        }
        puts("");
    }
}