# UFV-ShellEmC
## Link do repositório: https://github.com/the-thiago/UFV-ShellEmC
###### - Leandro Guimarães Oliveira - 4835
###### - Thiago Moreira de Souza - 6011
###### - Gabriel Antunes Fernandes Fonseca - 6039

#### Trabalho executado em graduação pela disciplina de Sistemas Operacionais na Universidade Federal de Viçosa.
#### Prof. Rodrigo Moreira - SIN 351

## SOBRE O PROJETO
Foi desenvolvido um Shell/Interpretador de Comandos (Command Line Interface - CLI) que é capaz de receber, iterativamente, entradas dos usuários (comandos), processá-los (caso ele exista) e exibir a saída na tela de Prompt. O Shell é comumente utilizado nos ambientes Unix utilizados no cotidiano. Ele é capaz que receber comandos concatenados por virgula(","), substituindo o pipe("|") do terminal. Para fechar o programa, basta utilizar o comando "quit". O programa ignora entradas e concatenações vazias.

## COMO UTILIZAR O SHELL

1) Para compilar o programa deve-se utilizar a palavra "make".

2) Para rodar o executável gerado é preciso digitar "./executavel".

3) Agora é possível executar vários comandos de um Interpretador de Comandos, podendo ser concatenados por virgula(","), substituindo o pipe("|") do terminal. Para fechar o programa, basta utilizar o comando "quit".


###  EXEMPLOS DE UTILIZAÇÃO

![Imagem que mostra a utilização do programa](https://github.com/the-thiago/UFV-ShellEmC/blob/master/PrintsReadMe/ExemplosDeUso.jpeg?raw=true)

> Exemplo de utilização do programa.

Apos ser compilado e executado, o cat concatenado com o grep mostra as linhas do funcoesShell.c que apresentam a palavra "fork". Através do ls -l, é listado os arquivos que estão no diretório do executável. Entradas e concatenações vazias são ignoradas pelo programa e é criado um programa através do comando touch. Por meio de outro ls, é possível ver o arquivo "file.txt" criado anteriormente. Por fim, o programa é fechado com o comando "quit".

###  COMO O PROGRAMA FOI IMPLEMENTADO
No arquivo onde está a main, um loop é executado enquanto o comando "quit" não é digitado pelo usuário. No loop, o usuário deve digitar um comando que será tratado pela função tratarEntrada(char *str).
Na função que trata a entrada, oque foi digitado é separado por vírgula e cada string gerada é separada por espaço, cada palavra é colocada em um vetor de string dinâmico. Esse vetor de argumentos é passado pra função executarComando(char* args[], char* proximoComando, int primeiroComandoOuNao, int* fd), que junto com outros argumentos decidem se os files descriptors(pipe, que faz a comunicação entre processos) devem ser lidos ou ser utilizado para escrita. A função executarComando, dependendo se é o primeiro comando e se tem comando concatenado a ser executado, lê ou escreve no pipe se necessário. Por meio do fork, um processo filho é criado e através do execvp executa o comando do shell.

