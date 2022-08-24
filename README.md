# ufv-shell-simulator-c
Contributors
###### - Leandro Guimarães Oliveira - 4835
###### - Thiago Moreira de Souza - 6011
###### - Gabriel Antunes Fernandes Fonseca - 6039

#### Project developed in undergraduate course of Operating Systems at the Federal University of Viçosa.
#### Prof. Rodrigo Moreira - SIN 351

## ABOUT THE PROJECT
A Shell/Command Interpreter (Command Line Interface - CLI) was developed that is capable of iteratively receiving user inputs (commands), processing them (if any) and displaying the output on the Prompt screen. The Shell is commonly used in Unix environments used in everyday life. It is able to receive commands concatenated by comma(","), replacing the pipe("|") of the terminal. To close the program, just use the "quit" command. The program ignores empty entries and concatenations.

## HOW TO USE THE SHELL

1) To compile the program you must use the word "make".

2) To run the generated executable, type "./executavel".

3) It is now possible to execute several commands from a Command Interpreter, which can be concatenated by comma(","), replacing the pipe("|") of the terminal. To close the program, just use the "quit" command.


###  EXAMPLES OF USE

![Image showing the use of the program](https://github.com/the-thiago/UFV-ShellEmC/blob/master/PrintsReadMe/ExemplosDeUso.jpeg?raw=true)

> Example of using the program.

After being compiled and executed, the cat concatenated with grep displays lines from funcoesShell.c that contain the word "fork". Through ls -l, the files that are in the executable directory are listed. Empty entries and concatenations are ignored by the program and a program is created using the touch command. Through another ls, you can see the file "file.txt" created earlier. Finally, the program is closed with the "quit" command.

###  HOW THE PROGRAM WAS IMPLEMENTED
In the file where main is, a loop is executed while the command "quit" is not typed by the user. In the loop, the user must type a command that will be handled by the tratarEntrada(char *str) function.
In the function that handles the input, what was typed is separated by comma and each generated string is separated by space, each word is placed in a dynamic string vector. This array of arguments is passed to the function executarComando(char* args[], char* proximoComando, int primeiroComandoOuNao, int* fd), which together with other arguments decide whether the files descriptors(pipe, which communicates between processes) should be read or be used for writing. The executarComando function, depending on whether it is the first command and whether it has a concatenated command to be executed, reads or writes to the pipe if necessary. Through fork, a child process is created and through execvp executes the shell command.
