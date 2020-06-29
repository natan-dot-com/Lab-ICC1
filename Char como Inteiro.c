/*
 *  Aluno: Natan Henrique Sanches (11795680) 
 *  ICMC/USP - Instituto de Ciências Matemáticas e Computação
 *  Imprimindo chars como inteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para leitura dos caracteres de entrada
char *readline(FILE *stream) {
    char *string = NULL;
    int pos = 0;
    do {
        string = (char *) realloc(string, (pos+2)*sizeof(char));
        string[pos] = (char) fgetc(stream);
        if (string[pos] == '\n' || string[pos] == '\r') {pos -= 1;}
    } while (string[pos++] != 'x');
    string[pos-1] = 'x';
    string[pos] = '\0';
    string = realloc(string, pos+1);

    return string;
}

// Função que executa o sort de um array
int sort(const void *a, const void *b) {
    if(*(char *) a == *(char *) b) {return 0;}
    else if (*(char *) a < *(char *) b) {return -1;}
    else {return 1;}
}

int main(int argc, char *argv[]) {
    char *characters = readline(stdin);
    qsort(characters, strlen(characters), sizeof(char), sort);

    int *integer_pointer = (int *) characters;
    for (int i = 0; i < strlen(characters)/4; i++) {
        printf("%d\n", *(integer_pointer+i));
    }

    free(characters);
    return 0;
}
