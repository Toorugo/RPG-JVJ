all:
	gcc -c ./src/impressao.c -I ./include -o ./obj/impressao.o
	gcc -c ./src/lista.c -I ./include -o ./obj/lista.o
	gcc -c ./src/menu.c -I ./include -o ./obj/menu.o
	gcc -c ./src/partida.c -I ./include -o ./obj/partida.o
	gcc -c ./src/personagem.c -I ./include -o ./obj/personagem.o
	gcc -c ./src/utils.c -I ./include -o ./obj/utils.o
	gcc -c ./src/main.c -I ./include -o ./obj/main.o
	gcc -g ./obj/*.o -o programa