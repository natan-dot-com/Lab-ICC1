/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Ataques e Tipos
*/

#include <stdio.h>
#include <stdlib.h>

#define STOP_READ -1

// Criação da matriz MxM.
float **matrixCreate(int matrix_member_number) {
    float **matrix= (float **) malloc(matrix_member_number*sizeof(float *));
    for (int i = 0; i < matrix_member_number; i++) {
        matrix[i] = (float *) calloc(matrix_member_number, sizeof(float));
    }

    return matrix;
}

// Leitura dos elementos da matriz.
void readMatrix(float ***matrix, int matrix_member_number) {
    for (int i = 0; i < matrix_member_number; i++) {
        for (int j = 0; j < matrix_member_number; j++) {
            scanf("%f", &(*matrix)[i][j]);
            if (j != matrix_member_number-1) {scanf(" ");}
        }
    }
} 

// Leitura dos ataques: seus respectivos tipos e seu poder de ataque.
int readSpells (int **spell_type, int **damage) {
    int spellsRead = 0;
    int aux = 0;
    do {
        scanf("%d", &aux);
        if (aux != STOP_READ) {
            (*damage) = (int *) realloc(*damage, (spellsRead+1)*sizeof(int));
            (*spell_type) = (int *) realloc(*spell_type, (spellsRead+1)*sizeof(int));
            
            (*damage)[spellsRead] = aux;
            scanf(" ");
            scanf("%d", &(*spell_type)[spellsRead]);
            
            spellsRead += 1;
        }
    } while(aux != STOP_READ);
    
    return spellsRead;
}

// Cálculo do melhor movimento para ser utilizado contra um monstro de determinado tipo.
int getBestMove(float **matrix, int spellsRead, int monster_type, int *spell_type, int *damage, float *bestDamage) {
	int bestType;
	for (int i = 0; i < spellsRead; i++) {
		float multiplier = matrix[spell_type[i]][monster_type];
		float turnDamage = multiplier*damage[i];
		if (turnDamage > *bestDamage) {
			*bestDamage = turnDamage;
			bestType = spell_type[i];
		}
	}
	return bestType;
}

void freeMatrix(float **matrix, int matrix_member_number) {
	for (int i = 0; i < matrix_member_number; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int main(int argc, char *argv[]) {
    int matrix_member_number;
    scanf("%d", &matrix_member_number);
    float **matrix = matrixCreate(matrix_member_number);
    readMatrix(&matrix, matrix_member_number);

    int *spell_type = NULL;
    int *damage = NULL;
    int spellsRead = readSpells(&spell_type, &damage);

	int monster_type;
	scanf("%d", &monster_type);

	float bestDamage = 0;
	int bestType = getBestMove(matrix, spellsRead, monster_type, spell_type, damage, &bestDamage);

	printf("O melhor ataque possui indice %d e dano %.2f\n", bestType, bestDamage);

	freeMatrix(matrix, matrix_member_number);
	free(spell_type);
	free(damage);

    return 0;
}
