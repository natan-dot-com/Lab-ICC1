/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Múltiplos de dois números em ordem crescente
*
*	Lógica utilizada na resolução do exercício:
*	Foi feita uma função para que extraisse n múltiplos de um inteiro i e n múltiplos de um inteiro j, respectivamente. Esses múltiplos foram
*	armazenados em um array, que logo depois foi submetido a um bubble sort incrementado que ordena o array em ordem crescente e joga os
*	termos repetidos para o final do array (nas casas extras). No fim, o array foi impresso até n múltiplos, como informado pelo usuário.
*/

#include <stdio.h>
#include <stdlib.h>

/* 
*	Função para cálculo de múltiplos:
*	a = Representa o número de múltiplos que serão calculados de cada número
*	b = Representa o primeiro número no qual os múltiplos serão calculados
*	c = Representa o segundo número no qual os múltiplos serão calculados
*/
int *multiplos(int a, int b, int c) {
	int *m = (int *) calloc(2*a, sizeof(int));
	for (int i = 0, j = 0; i < a; i++, j++) {
		m[i+j] = b*i;
		m[i+j+1] = c*i;
	}
	return m;
}

int main(void) {
	int n;
	int i;
	int j;

	scanf("%d", &n);
	scanf("%d", &i);
	scanf("%d", &j);

	// Cálculo dos n múltiplos de i e j dentro de um array
	int *mult = multiplos(n, i, j);

	// Bubble sort incrementado
	for (int cont = 1; cont < 2*n; cont++) {
		for (int x = 0; x < 2*n -1; x++) {
			// Para ordenação
			if (mult[x] > mult[x+1]) {
				int temp;
				temp = mult[x];
				mult[x] = mult[x+1];
				mult[x+1] = temp;
			}
			// Para retirar os termos repetidos do meio do array
			if (mult[x] == mult[x+1]) {
				for (int y = x+1; y < 2*n -1; y++) {
					mult[y] = mult[y+1];
				}
			}
		}
	}

	// Saída dos múltiplos desejados
	for (int w = 0; w < n; w++) {
		printf("%d\n", mult[w]);
	}

	free (mult);
	return 0;
}
