#ifndef PERSONAGENS_H
#define PERSONAGENS_H
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

typedef struct _personagem{
    int nivel;
    char nome[50];
    int dado;
    int iniciativa;
} Personagem;


Personagem* criar_personagem(char*, int, int);

bool verificar_dado(int);

void liberar_personagem(Personagem*);

#endif