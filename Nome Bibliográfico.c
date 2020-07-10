/*
 *  Aluno: Natan Henrique Sanches (11795680)
 *  ICMC/USP - Instituto de Ciências Matemáticas e Computação
 *  Nome bibliográfico
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline(FILE *stream) {
    char *string = NULL;
    int pos = 0;
    do {
        string = (char *) realloc(string, (pos+1)*sizeof(char));
        string[pos] = (char) fgetc(stream);
    } while(string[pos++] != '\n' && !feof(stream));
    string[pos-1] = '\0';
    if (pos >= 2 && string[pos-2] == '\r') {
        string[pos-2] = '\0';
    }

    return string;
}

// Função contadora de palavras numa string
int wordCounter(char *string) {
    int counter = 0;
    for (int i = 0; i < strlen(string)-1; i++) {
        if (string[i] == ' ') {counter += 1;}
    }

    return counter+1;
}

// Função para extrair o último nome
char *extractLastName(char *string, int counter) {
    int space_counter = 0;
    char *last_name = NULL;
    int pos = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {space_counter += 1;}   
        if (space_counter == counter-1) {
            if (string[i] != ' ') {
                last_name = (char *) realloc(last_name, (pos+2)*sizeof(char));
                last_name[pos++] = string[i];
            }
        }
    }
    last_name[pos] = '\0';

    return last_name;
}

// Função que transforma o último nome em uppercase
void toUppercase(char **string) {
    for (int i = 0; (*string)[i] != '\0'; i++) {
        if ((*string)[i] >= 'a' && (*string)[i] <= 'z') {
            (*string)[i] = (*string)[i] - 32;
        }
    }
}

// Função que remove o último nome da string original
void removeLastName(char **string, int counter) {
    int space_counter = 0;
    for (int i = 0; i < strlen(*string); i++) {
        if ((*string)[i] == ' ') {space_counter += 1;}
        if (space_counter == counter-1) {(*string)[i] = '\0'; return;}
    }
}

int main(int argc, char *argv[]) {
    char *string = readline(stdin); 
    int counter = wordCounter(string);
    char *last_name = extractLastName(string, counter);
    toUppercase(&last_name);
    removeLastName(&string, counter);

    printf("%s, %s\n", last_name, string);
    free(string);
    free(last_name);
    return 0;
}
