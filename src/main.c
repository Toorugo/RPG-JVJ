#include "tudojunto.h"

int main(){
    int resposta=1;
    do{
        Lista* personagens = menu(&resposta);
        if(resposta) partida(personagens, &resposta);
    }while(resposta);
    return 0;
}