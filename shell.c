#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void executarComando(char* args[]){

	char* comando = args[0];

	if (args[0] == NULL){
		return;
	}
	if (strcmp(args[0], "quit") == 0) {
		//printf("quitando\n");
		exit(0);
	}

	pid_t pid = fork();
	if (pid == -1) {
		perror("Erro no fork");
	}
	if (pid == 0) { // Filho executa esse bloco
		//printf("---Filho %d\n", (int)pid);		
		if (execvp(args[0], args) == -1) {
			perror("Erro no execv");
		}
		exit(0); // Termina processo filho
	}

	// Processo pai espera filho terminar de executar
	if (wait(0) == -1) {
		perror("Erro no wait");
	}
	
	//printf("---Pai %d\n", (int)pid);
}

void splits(char *str){
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
	char **args;
	int indice = 0, i = 0;
    char *end_str;
    char *token = strtok_r(str, ",", &end_str);

    while (token != NULL) {
        char *end_token;
        //printf("comando completo = '%s'\n", token);
        char *token2 = strtok_r(token, " ", &end_token);

        args = malloc(sizeof(char*)*512); //Aloca 512 ponteiros de char, ou seja, 512 strings **vazias**, ainda **não alocadas**.
        while (token2 != NULL) {
            //printf("parte = %s\n", token2);

            // Criar args aqui com cada token2
            
  			args[indice] = malloc(sizeof(char)*512); //String Dinâmica Normal
			args[indice] = token2;			
			//printf("args[%d] = %s\n", indice, args[indice]);
			indice++;

            // Fim

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

int main( ){

	char entrada[512];
	do{
		printf("\e[92m");	// Muda a cor da fonte do terminal para verde
		printf("meu-shell> ");		
		printf("\e[0m");	// Volta a cor da fonte do terminal para branco
		gets(entrada);
		fflush(stdin);
		splits(entrada);

	}while(1);

	return 0;
}
