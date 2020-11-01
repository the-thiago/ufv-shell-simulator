
executavel: main.o funcoesShell.o
	gcc main.o funcoesShell.o -o executavel

main.o: main.c
	gcc -c -Wall main.c

funcoesShell.o: funcoesShell.c funcoesShell.h
	gcc -c -Wall funcoesShell.c

clean:
	rm *.o executavel