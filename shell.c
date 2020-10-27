#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
void split(char *strs){

	char str[] = "strtok needs to be called several     times to split a string";
	int init_size = strlen(str);
	char delim[] = " ";

	char *ptr = strtok(str, delim);

	while (ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}

}*/
// Faz o split por espaços e por ;
void split(char entrada[512]){

	//char str[] = "strtok needs to be called several     times to split a string";
	char str[512];
	strcpy(str, entrada);
	char delim[] = ",";

	char *ptr = strtok(str, delim);
	while (ptr != NULL) // Split por virgula
	{
		printf("'%s'\n", ptr);
		printf("VIRGULA\n");
		while(){

		}




		// Split por virgula
		ptr = strtok(NULL, delim);
	}

}


int main(){
	char strs;
	char entrada[512];
	

	int i = 0;

	do{
		printf("meu-shell>");
		gets(entrada);
		fflush(stdin);
		printf("%s\n", entrada);
		i++;
	}while(i<3);

	


	
	split(entrada);
	return 0;

}






