#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoesShell.h"

int main( ){

	int len = 0;
	char entrada[TAMANHO_ENTRADA];
	do{
		printf("\e[92m");	// Muda a cor da fonte do terminal para verde
		printf("meu-shell> ");		
		printf("\e[0m");	// Volta a cor da fonte do terminal para branco
		//gets(entrada); Estavamos usando gets mas o compilar recomendou usar fgets
		fgets(entrada, sizeof(entrada), stdin);
		len = strlen(entrada);
		// Diferentemente do gets, o fgets coloca um '\n' no fim da entrada que estava trazendo erros
		if (len > 0 && entrada[len-1] == '\n') 
            entrada[len-1] = '\0';  
		fflush(stdin);
		tratarEntrada(entrada);	// Faz split por ',' e depois por ' ', chama a funcao executarComando()

	}while(1);

	return 0;
}
