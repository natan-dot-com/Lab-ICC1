/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Algoritmo de Busca Binária
*/

#include <stdio.h>
#include <stdlib.h>

// Macro para chave não existente
#define NOT_FOUND -1

// Função para leitura do array a ser submetido à busca
void readArray(int *array, const int array_size) {
	for (int i = 0; i < array_size-1; i++) {
		scanf("%d ", &array[i]);
	}
	scanf("%d", &array[array_size-1]);

	return;
}

// Função para ordenar o array em ordem crescente (bubble sort)
void arraySort (int *array, const int array_size) {
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size-1; j++) {
			if (array[j] > array[j+1]) {
				int temp;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

	return;
}

// Função que executa a busca binária
int binarySearch (const int *array, const int array_size, const int key) {
	int min = 0;
	int max = array_size-1;
	while (min <= max) {
		int guess = (min+max)/2;
		if (array[guess] == key) {return guess;}
		if (array[guess] < key) {min = guess+1;}
		if (array[guess] > key) {max = guess-1;}
	}

	printf("Chave inexistente\n");
	return NOT_FOUND;
}

int main(int argc, char *argv[]) {
	int array_size;
	scanf("%d ", &array_size);

	int key;
	scanf("%d", &key);

	int *array = (int *) malloc(array_size*sizeof(int));
	readArray(array, array_size);
	arraySort(array, array_size);

	int result;
	result = binarySearch(array, array_size, key);
	if (result != NOT_FOUND) {printf("%d\n", result);}

	free(array);
	return 0;
}
