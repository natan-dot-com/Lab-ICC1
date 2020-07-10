/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Mistura de cores
*/

#include <stdio.h>
#include <stdlib.h>

#define START -1
#define RESULT -2

// Cria a matrix onde permanecerão os valores das cores em RGB
int **createMatrix() {
	int **matrix = (int **) malloc(6*sizeof(int *));
	for (int i = 0; i < 6; i++) {
		matrix[i] = (int *) malloc(3*sizeof(int));
		scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
	}

	return matrix;
}

// Exibe a matrix na tela
void printMatrix(int **matrix, const int type) {
	switch (type) {
		case START : {printf("Start:\n"); break;}
		case RESULT : {printf("\nResult:\n"); break;}
	}

	for (int i = 0; i < 6; i++) {
		printf("Color(%d): [\t%d\t%d\t%d\t]\n", i, matrix[i][0], matrix[i][1], matrix[i][2]);
	}
}

// Faz a mistura das cores considerando as linhas da matriz solicitadas
int *getMixture(int **matrix, int first_sample, int second_sample) {
	int *mixture = (int *) malloc(3*sizeof(int));

	for (int i = 0; i < 3; i++) {
		mixture[i] = matrix[first_sample][i]/2 + matrix[second_sample][i]/2;
	}

	return mixture;
}

// "Pinta" a matriz na linha solicitada, somando o valor da mistura ao valor já existente naquela posição
void paintMatrix(int ***matrix, int *mixture , int third_sample) {
	for (int i = 0; i < 3; i++) {
		(*matrix)[third_sample][i] += mixture[i];
		if ((*matrix)[third_sample][i] > 255) {
			(*matrix)[third_sample][i] = 255;
		}
	}
}

void freeMatrix(int **matrix) {
	for(int i = 0; i < 6; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int main(int argc, char *argv[]) {
	int first_sample, second_sample, third_sample;
	scanf("%d %d %d", &first_sample, &second_sample, &third_sample);

	int **palette = createMatrix();
	printMatrix(palette, START);

	int *mixture = getMixture(palette, first_sample, second_sample);
	paintMatrix(&palette, mixture, third_sample);
	printMatrix(palette, RESULT);

	freeMatrix(palette);
	free(mixture);
	return 0;
}
