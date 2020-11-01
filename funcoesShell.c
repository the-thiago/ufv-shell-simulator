#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "funcoesShell.h"

void executarComando(char* args[]){

	if (args[0] == NULL){ // Não digitou nada alem de espaços e virgulas.
		return;
	}
	if (strcmp(args[0], "quit") == 0) {
		//printf("quitando\n");
		exit(0);
	}

	pid_t pid = fork(); // Cria um processo filho
	if (pid == -1) {
		perror("Erro no fork");
	}
	if (pid == 0) { // Filho executa esse bloco
		//printf("---Filho %d\n", (int)pid);		
		if (execvp(args[0], args) == -1) {
			perror("Erro ao executar comando"); // Printa errno
		}
		exit(0); // Termina processo filho
	}

	// Processo pai espera filho terminar de executar
	if (wait(0) == -1) {
		perror("Erro no wait");
	}	
	//printf("---Pai %d\n", (int)pid);
}

void tratarEntrada(char *str){

	char **args;
	int indice = 0; // Ultimo args adicionado ao vetor de strings(char **args)
    char *end_str;
    char *token = strtok_r(str, ",", &end_str);

    while (token != NULL) { // Split por virgula ','
    	//printf("comando completo: '%s'\n", token);
        char *end_token;        
        char *token2 = strtok_r(token, " ", &end_token);

        // Vetor de Strings criado
        args = malloc(sizeof(char*)*TAMANHO_ENTRADA); //Aloca 512 ponteiros de char, ou seja, 512 strings **vazias**, ainda **não alocadas**.
        while (token2 != NULL) { // Split por espaço ' '
            //printf("pedaço do comando: %s\n", token2);

            // Criar args aqui com cada token2(Pedaço do comando que estão sendo separados por ' '),          
  			args[indice] = malloc(sizeof(char)*TAMANHO_ENTRADA);
			args[indice] = token2;			
			//printf("args[%d] = %s\n", indice, args[indice]);
			indice++;

            token2 = strtok_r(NULL, " ", &end_token);
        }
        args[indice] = NULL; // No execvp, o ultimo args deve ser NULL
        //printf("Executando um comando aq\n");
        executarComando(args);
        // Desalocando a memoria        
		free(args);
		indice = 0;

        token = strtok_r(NULL, ",", &end_str);
    }
}
