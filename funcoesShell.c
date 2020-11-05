#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "funcoesShell.h"

void executarComando(char* args[], char* proximoComando, int primeiroComandoOuNao, int* fd){

	if (args[0] == NULL){ // Não digitou nada alem de espaços e virgulas.
		return;
	}
	if (strcmp(args[0], "quit") == 0) { // Fecha programa
		exit(0);
	}

	// É o primeiro comando e tem mais comandos concatenados por ','
	if(primeiroComandoOuNao == 1 && proximoComando != NULL){ 
		pid_t pid = fork(); // Cria um processo filho
		if (pid == -1) {
			perror("Erro no fork");
		}
		if (pid == 0) { // Filho executa esse bloco		
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);			
			close(fd[1]);

			if (execvp(args[0], args) == -1) {
				perror("Erro ao executar comando"); // Printa errno
			}
		}

	} else if(primeiroComandoOuNao == 0 && proximoComando == NULL){ // Não é o primeiro e é o ultimo comando

		pid_t pid = fork(); // Cria um processo filho
		if (pid == -1) {
			perror("Erro no fork");
		}
		if (pid == 0) { // Filho executa esse bloco	
			dup2(fd[0], STDIN_FILENO);	
			close(fd[0]);
			close(fd[1]);

			if (execvp(args[0], args) == -1) {
				perror("Erro ao executar comando"); // Printa errno
			}
		}
		// Fecha pipe do programa principal
		close(fd[0]);
		close(fd[1]);

	} else if(primeiroComandoOuNao == 1 && proximoComando == NULL){ // Um unico comando, primeiro e ultimo

		pid_t pid = fork(); // Cria um processo filho
		if (pid == -1) {
			perror("Erro no fork");
		}
		if (pid == 0) { // Filho executa esse bloco	
			if (execvp(args[0], args) == -1) {
				perror("Erro ao executar comando"); // Printa errno
			}
		}		
	}

	// Processo pai espera filho terminar de executar
	if (wait(0) == -1) {
		perror("Erro no wait");
	}	
}

void tratarEntrada(char *str){
	int primeiroComandoOuNao = 1;
	int fd[2];		// files descriptors, faz a comunicação entre processos
	char **args;
	int indice = 0; // Indice do ultimo args adicionado ao vetor de strings(char **args)
	char *end_str;

	char *token = strtok_r(str, ",", &end_str);

	if (pipe(fd) == -1) {
		perror("Erro no pipe");
		return ;
	}

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
			indice++;

			token2 = strtok_r(NULL, " ", &end_token);
		}
		args[indice] = NULL; // No execvp, o ultimo args deve ser NULL       

		token = strtok_r(NULL, ",", &end_str); // Pega proximo comando completo...
		// Executa o comando que está no vetor de string args
		executarComando(args, token, primeiroComandoOuNao, fd);
		// Desalocando a memoria        
		free(args);
		indice = 0;
		if (primeiroComandoOuNao == 1){
			primeiroComandoOuNao = 0;
		}
	}
}
