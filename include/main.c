#include "tudojunto.h"

int main(){
    int resposta;
    do{
        lista_p personagens = menu(&resposta);
        if(resposta)partida(personagens);
    }while(resposta);
    return 0;
}