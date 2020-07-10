/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Adicionando sobrenomes	
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

// Cria a matriz com todos os nomes lidos
char **createMatrix(int *counter) {
	char **nameMatrix = NULL;
	int flag = 0;
	for (*counter = 0; flag != END_OF_READ; (*counter)++) {
		nameMatrix = (char **) realloc(nameMatrix, ((*counter)+1)*sizeof(char *));
		nameMatrix[*counter] = readline(stdin, &flag);
	}

	return nameMatrix;
}

void printMatrix(char **matrix, int counter) {
	for (int i = 0; i < counter; i++) {
		printf("%s\n", matrix[i]);
	}
}

void freeMatrix(char **matrix, int counter) {
	for (int i = 0; i < counter; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

// Pega o último nome de uma string fornecida. Utilizado na função de criação da matriz de últimos nomes
char *getLastName(char *string) {
	char *lastName = NULL;
	int flag = 0;
	int pos;
	for (pos = strlen(string)-1; flag != END_OF_READ; pos--) {
		if (string[pos] == ' ') {
			int i;
			for (i = 0; string[pos] != '\0'; i++, pos++) {
				lastName = (char *) realloc(lastName, (i+2)*sizeof(char));
				lastName[i] = string[pos];
			}
			lastName[i] = '\0';
			flag = END_OF_READ;
		}
	}

	return lastName;
}

// Cria a matriz de últimos nomes das strings com índice par na matriz base
char **getLastNameMatrix(char **matrix, int counter, int *lastNameCounter) {
	char **lastNameMatrix = NULL;
	int pos = 0;
	int i;
	for (i = 0; i < counter; i += 2, pos++) {
		lastNameMatrix = (char **) realloc(lastNameMatrix, (pos+1)*sizeof(char *));
		lastNameMatrix[pos] = getLastName(matrix[i]);
	}
	*lastNameCounter = pos;

	return lastNameMatrix;
}

// Concatena as strings de índice ímpar com o último nome da string anterior a ela
void catStrings(char **matrix, int counter) {
	int pos = 0;
	int lastNameCounter = 0;
	char **lastNameMatrix = getLastNameMatrix(matrix, counter, &lastNameCounter);
	for (int i = 1; i < counter && pos < lastNameCounter; i += 2, pos++) {
		int lastNameLengh = strlen(lastNameMatrix[pos]);
		int nameLengh = strlen(matrix[i]);
		matrix[i] = (char *) realloc(matrix[i], (lastNameLengh+nameLengh+1)*sizeof(char));
		strcat(matrix[i], lastNameMatrix[pos]);
	}
	freeMatrix(lastNameMatrix, lastNameCounter);
}

int main(int argc, char *argv[]) {
	int counter;
	char **nameMatrix = createMatrix(&counter);
	catStrings(nameMatrix, counter);
	printMatrix(nameMatrix, counter);
	freeMatrix(nameMatrix, counter);
	return 0;
}

