/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Long
*/

#include <stdio.h>

int main(void) {
	// n = Long a ser colocado de entrada
	long long int n;
	scanf("%lld", &n);

	// Posicionamento do ponteiro p no endereço do primeiro byte do long n
	unsigned char *p = (unsigned char *) &n;

	// Impressão de cada byte de n a partir do ponteiro p
	for (int i = 0; i < 8; i++) {
		printf("%x\n", *(p+i));
	}
}	