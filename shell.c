#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void split(char *str){

	//char str[] = *strs;


	// Separa os comandos concatenados por , (virgular)
	char delimComandos[] = ",";
	char *ptr1 = strtok(str, delimComandos);

	while (ptr1 != NULL)
	{
		printf("'%s'\n\n", ptr1);
		char *ptrAux = ptr1;
		// Separa por espaços, comando + args
		char delimPalavras[] = " ";
		char *ptr2 = strtok(ptr1, delimPalavras);
		while(ptr2 != NULL){
			printf("'%s'\n", ptr2);

			ptr2 = strtok(NULL, delimPalavras);
		}
		ptr1 = ptrAux;
		ptr1 = strtok(NULL, delimComandos);
	}

}

int main( ){
	/*
  	// Cria um professo filho com pid == 0.
	pid_t pid = fork();
	if (pid == -1) {
		perror("Erro no fork");
	}
	if (pid == 0) { // Filho executa esse bloco
		printf("Filho %d\n", (int)pid);		
	}
	if (pid > 0) { // Pai, executa esse bloco  		
  		// Espera a execução do processo filho, filho tem pid == 0.
  		if (wait(0) == -1) {
  			perror("Erro no wait");
  		}
		
		printf("Pai %d\n", (int)pid);
	}
	*/
	char entrada[512];
	do{

		printf("meu-shell> ");
		gets(entrada);
		fflush(stdin);
		char* args[4];
		char* comando = entrada;

		args[0] = comando;
		args[1] = NULL;
		args[2] = NULL;
		args[3] = NULL;

		split(entrada);

		if (strcmp(args[0], "quit") == 0) {
			printf("quitando\n");
			exit(0);
		}

		pid_t pid = fork();
		if (pid == -1) {
			perror("Erro no fork");
		}
		if (pid == 0) { // Filho executa esse bloco
			printf("---Filho %d\n", (int)pid);		
			if (execvp(args[0], args) == -1) {
				perror("Erro no execv");
			}
			exit(0);
		}

		// Processo pai espera filho terminar de executar
		if (wait(0) == -1) {
			perror("Erro no wait");
		}
		
		printf("---Pai %d\n", (int)pid);


	}while(1);
	


		


	

	return 0;

  //exit(0);
}
