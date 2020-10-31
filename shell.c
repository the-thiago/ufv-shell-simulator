#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void split(char *str){
	/*
	char delimVirgula[] = " ";
	char *token;

	token = strtok(str, delimVirgula);
	while( token != NULL ) {
		printf( "'%s'\n", token );
		// Inserir outro split
		token = strtok(NULL, delimVirgula);
	}
	*/
	
    char *end_str;
    char *token = strtok_r(str, ",", &end_str);

    while (token != NULL) {
        char *end_token;
        printf("comando completo = %s\n", token);
        char *token2 = strtok_r(token, " ", &end_token);
        while (token2 != NULL) {
            printf("parte = %s\n", token2);

            // Criar args aqui com tokens2

            token2 = strtok_r(NULL, " ", &end_token);
        }
        token = strtok_r(NULL, ",", &end_str);
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
