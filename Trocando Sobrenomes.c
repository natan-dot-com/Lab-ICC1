/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Trocando sobrenomes	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_OF_READ -1

char *readline(FILE *stream, int *flag) {
	char *string = NULL;
	int pos = 0;
	do {
		string = (char *) realloc(string, (pos+1)*sizeof(char));
		string[pos] = (char) fgetc(stream);
		if (string[pos] == '$') {
			 *flag = END_OF_READ;
			 pos -= 1;
		}
	} while(string[pos++] != '\n' && !feof(stream));
	string[pos-1] = '\0';
	if (pos >= 2 && string[pos-2] == '\r') {
		string[pos-2] = '\0';
	}

	return string;
}

// Função para criação de uma matriz de nomes
int createMatrix(char ***matrix) {
	int flag = 0;
	int counter;
	for (counter = 0; flag != END_OF_READ; counter++) {
		(*matrix) = (char **) realloc((*matrix), (counter+1)*sizeof(char *));
		(*matrix)[counter] = readline(stdin, &flag);
	}
	return counter;
}

// Função para remoção do último nome da string original e a criação de uma string a parte com esse nome
char *setLastNamePointer(char *string) {
	char *lastName = NULL;
	int pos;
	int aux;
	int flag = 0;
	for (pos = strlen(string)-1; flag != END_OF_READ; pos--) {
		if (string[pos] == ' ') {
			aux = pos;
			pos += 1;
			int i;
			for (i = 0; string[pos] != '\0'; i++, pos++) {
				lastName = (char *) realloc(lastName, (i+2)*sizeof(char));
				lastName[i] = string[pos];
			}
			lastName[i] = '\0';
			flag = END_OF_READ;
		}
	}
	string[aux] = '\0';

	return lastName;
}

// Função para criação de uma matriz de últimos nomes
char **getLastNames(char **matrix, int counter) {
	char **lastNamesMatrix = NULL;
	for (int i = 0; i < counter; i++) {
		lastNamesMatrix = (char **) realloc(lastNamesMatrix, (i+1)*sizeof(char *));
		lastNamesMatrix[i] = setLastNamePointer(matrix[i]);
	}
	
	return lastNamesMatrix;
}

// Função que printa os nomes com a devida troca
void printNames(char **matrix, char **lastNames, int counter) {
	for (int j = 0; j < counter; j++) {
		printf("%s %s\n", matrix[j], lastNames[counter-1-j]); 
	}
}

void freeMatrix(char **matrix, int counter) {
	for (int i = 0; i < counter; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int main(int argc, char *argv[]) {
	char **nameMatrix = NULL;
	int counter = createMatrix(&nameMatrix);
	char **lastNamesMatrix = NULL;
	lastNamesMatrix = getLastNames(nameMatrix, counter);
	printNames(nameMatrix, lastNamesMatrix, counter);

	freeMatrix(nameMatrix, counter);
	freeMatrix(lastNamesMatrix, counter);
	return 0;
}
