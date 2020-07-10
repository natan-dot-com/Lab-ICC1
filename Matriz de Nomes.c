/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Matriz de nomes	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função baseada no arquivo do Leitura.c no run.codes, para leitura dos nomes
char *readline(FILE *stream) {
	char *string = NULL;
	int pos = 0;
	string = (char *) malloc(50*sizeof(char));
	do {
		string[pos] = (char) fgetc(stream);
		if (string[pos] == '\r') {pos -= 1;}
	} while(string[pos++] != '\n' && !feof(stream) && pos < 50);
	string[pos-1] = '\0';

	return string;
}

// Função que lê todos os nomes e cria uma matriz com eles
char **readNames(FILE *stream, int *counter) {
	char **nameMatrix = NULL;
	int i;
	for (i = 0; !feof(stream); i++) {
		if (!feof(stream)) {
			nameMatrix = (char **) realloc(nameMatrix, (i+1)*sizeof(char *));
			nameMatrix[i] = readline(stream);
		}
	}
	// O contador não irá contar a linha vazia no final do arquivo
	*counter = i-1;

	return nameMatrix;
}

// Função que executa um bubble sort para ordenação alfabética. Ao invés de ser utilizada uma alocação dinâmica com a função strcpy
// para transferir o conteúdo para o ponteiro aux_ptr, foi preverível que ele apenas segurasse o endereço da string que será trocada
// de lugar, sem receber seu conteúdo.
void sortStrings(char ***nameMatrix, int counter) {
	char *aux_ptr;
	for (int i = 0; i < counter-1; i++) {
		for (int j = i+1; j < counter; j++) {
			if(strcmp((*nameMatrix)[i], (*nameMatrix)[j]) > 0) {
				aux_ptr = (*nameMatrix)[i];
				(*nameMatrix)[i] = (*nameMatrix)[j];
				(*nameMatrix)[j] = aux_ptr;
				
			}
		}
	}
}

void printMatrix(char **nameMatrix, int nameCounter) {
	for (int i = 0; i < nameCounter; i++) {
		printf("%s\n", nameMatrix[i]);
	}
}

void freeMatrix(char **nameMatrix, int counter) {
	for (int i = 0; i < counter+1; i++) {
		free(nameMatrix[i]);
	}
	free(nameMatrix);
}

int main(int argc, char *argv[]) {
	int nameCounter = 0;
	char **nameMatrix = readNames(stdin, &nameCounter);
	sortStrings(&nameMatrix, nameCounter);
	printMatrix(nameMatrix, nameCounter);
	freeMatrix(nameMatrix, nameCounter);

	return 0;
}
