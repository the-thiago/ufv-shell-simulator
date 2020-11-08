# UFV-ShellEmC
## Link do repositório: https://github.com/the-thiago/UFV-ShellEmC
###### - Leandro Guimarães Oliveira - 4835
###### - Thiago Moreira de Souza - 6011
###### - Gabriel Antunes Fernandes Fonseca - 6039

#### Trabalho executado em graduação pela disciplina de Sistemas Operacionais na Universidade Federal de Viçosa.
####Prof. Rodrigo Moreira - SIN 351

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

