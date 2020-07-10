/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Corra para a base
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define X_AXIS 0
#define Y_AXIS 1

// Criação da matriz.
int **matrixCreate(int row, int col) {
	int **matrix = (int **) malloc(row*sizeof(int *));
	for (int i = 0; i < row; i++) {
		matrix[i] = (int *) calloc(col, sizeof(int));
	}

	return matrix;
}

// Leitura dos elementos da matriz e identificação da posição da base.
int *readMatrix(int ***matrix, int row, int col) {
	int *basePosition = (int *) calloc(2, sizeof(int));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &(*matrix)[i][j]);
			if (j != row-1) {scanf(" ");}
			if ((*matrix)[i][j] == 1) {
				basePosition[X_AXIS] = j;
				basePosition[Y_AXIS] = i;
			}
		}
	}

	return basePosition;
}

// Cálculo da distância euclideana.
double euclideanDistance(int *playerPosition, int *basePosition) {
	double euclidean = sqrt(pow((playerPosition[X_AXIS]-basePosition[X_AXIS]), 2)+pow((playerPosition[Y_AXIS]-basePosition[Y_AXIS]), 2));
	return euclidean;
}

void freeMatrix(int **matrix, int row) {
	for(int i = 0; i < row; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

// Os vetores basePosition e playerPosition armazenam, respectivamente, os valores em X (coluna) e em Y (linha) das posições de cada um.
int main(int argc, char *argv[]) {
	int row, col;
	scanf("%d %d", &row, &col);

	int **matrix = matrixCreate(row, col);

	int *playerPosition = (int *) calloc(2, sizeof(int));
	double movement;
	scanf("%d %d %lf", &playerPosition[Y_AXIS], &playerPosition[X_AXIS], &movement);

	int *basePosition = readMatrix(&matrix, row, col);

	double euclidean = euclideanDistance(playerPosition, basePosition);
	if (euclidean <= movement) {
		printf("Voce escapou!\n");
	} else {
		printf("Game Over!\n");
	}

	freeMatrix(matrix, row);
	free(playerPosition);
	free(basePosition);

	return 0;
}
