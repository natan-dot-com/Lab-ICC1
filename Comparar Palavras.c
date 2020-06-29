/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Comparar palavras
*
*	Lógica utilizada na resolução do exercício:
*	Para evitar problemas com case sensitive, utilizamos uma função que transforme todas as maiúsculas em minúsculas. A lógica utilizada
*	em cada caso será descrita posteriormente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para encontrar valor mínimo entre dois inteiros, utilizado para detectar a menor string.
int min(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// Função contra case sensitive para strings. Utilizada nas palavras de entrada.
void sensitive_s(char *p) {
	int tam = strlen(p);
	for (int i = 0; i < tam; i++) {
		if (p[i] >= 65 && p[i] <= 90)
			p[i] = p[i] + 32;
	}
}

// Função contra case sensitive para chars. Utilizada na chave de entrada (casos 4 e 5).
void sensitive_c(char *p) {
	if (*p >= 65 && *p <= 90)
		*p = *p + 32;
}

int main(void) {
	// op = Operador (1 a 5)
	// word1 = Primeira palavra a ser comparada
	// word2 = Segunda palavra a ser comparada
	int op;
	char *word1;
	char *word2;

	scanf("%d", &op);
	scanf("%ms", &word1);
	scanf("%ms", &word2);

	sensitive_s(word1);
	sensitive_s(word2);

	int lengh1 = strlen(word1);
	int lengh2 = strlen(word2);

	switch (op) {
		/*	Caso 1: Maior tamanho
		**	Compara o tamanho de ambas as strings e printa na tela a que possuir maior tamanho
		*/ 
		case 1 : {
			if (lengh1 > lengh2) {
				printf("1\n");
				break;
			}
			else if (lengh1 < lengh2) {
				printf("2\n");
				break;
			}
			else if (lengh1 == lengh2) {
				printf("0\n");
				break;
			}
		}
		/*	Caso 2: Ordem alfabética
		**	É escolhido o tamanho da menor string e ambas strings são comparadas com base nele. Caso haja alguma letra diferente que dê para
		**	definir qual das palavras está antes no alfabeto, o programa finaliza. Caso todas as letras nesse intervalo sejam iguais, o mé-
		**	todo de comparação irá se basear no tamanho das strings: se o tamanho de ambas forem igual (implica que as palavras são iguais),
		**	há um empate; se o tamanho de uma string for maior do que o de outra, significa que a string de maior tamanho virá depois no al-
		**	fabeto, visto que ela possuirá mais letras do que a outra string.
		*/
		case 2 : {
			int test = 0;
			int limit = min(lengh1, lengh2);
			for (int i = 0; test == 0 && i < limit; i++) {
				if (word1[i] > word2[i]) {
					printf("2\n");
					test++;
				}
				else if (word1[i] < word2[i]) {
					printf("1\n");
					test++;
				}
			}
			// Se possuir alguma letra diferente que dê para definir qual das strings vêm primeiro no alfabeto (implica test == 1)
			if (test == 1)
				break;
			// Se as strings forem iguais até o limite definido (implica test == 0)
			else {
				if (lengh1 == lengh2) {
					printf("0\n");
				} else if (lengh1 > lengh2) {
					printf("2\n");
				} else if (lengh1 < lengh2) {
					printf("1\n");
				}
			}
			break;
		}
		/*	Caso 3: Soma de cada letra na forma A0Z25
		**	Duas variáveis sum1 e sum2 são responsáveis por somar cada uma das letras das strings 1 e 2, respectivamente, com a devida
		**	conversão A0Z25. A comparação é feita ao final.
		*/
		case 3 : {
			int sum1 = 0, sum2 = 0;
			for (int i = 0; i < lengh1; i++) {
				sum1 += word1[i] - 97; 
			}
			for (int j = 0; j < lengh2; j++) {
				sum2 += word2[j] - 97;
			}
			if (sum1 > sum2) {
				printf("1\n");
				break;
			}
			else if (sum1 < sum2) {
				printf("2\n");
				break;
			}
			else {
				printf("0\n");
				break;
			}
		}
		/*	Caso 4: Mais repetições de determinada letra
		**	A variável key é responsável por guardar qual letra será usada como parâmetro para as repetições. A variável repeat, iniciali-
		**	zada em zero, representa o número de vezes que cada letra foi repetida. Como cada repetição na primeira string incrementa a
		** 	variável repeat, e cada repetição na segunda string decrementa a mesma, o parâmetro a ser analisado é se repeat será positivo,
		**	negativo ou nulo ao final da análise.
		*/
		case 4 : {
			char key;
			scanf(" %c", &key);
			sensitive_c(&key);

			int repeat = 0;
			for (int i = 0; i < lengh1; i++) {
				if (word1[i] == key)
					repeat++;
			}
			for (int j = 0; j < lengh2; j++) {
				if (word2[j] == key)
					repeat--;
			}

			if (repeat > 0) {
				printf("1\n");
				break;
			}
			else if (repeat < 0) {
				printf("2\n");
				break;
			}
			else {
				printf("0\n");
				break;
			}
		}
		/*	Caso 5: Letra aparecer primeiro
		**	A variável key é responsável por guardar qual letra será usada como parâmetro. As variáveis test1 e test2 indicam se
		**	houve aparecimento da letra requerida nas strings. Se test1 == test2 == 0, a letra não apareceu em nenhuma das strings
		**	e, assim, resulta num empate. As variáveis pos1 e pos2 guardam a posição na qual a letra apareceu pela primeira vez
		**	na string; elas serão comparadas somente se test1 != 0 ou test2 != 0. A comparação é feita ao final.
		*/
		case 5 : {
			char key;
			scanf(" %c", &key);
			sensitive_c(&key);

			int test1 = 0, test2 = 0, pos1, pos2;
			for (int i = 0; i < lengh1 && test1 == 0; i++) {
				if (word1[i] == key) {
					pos1 = i;	
					test1++;
				}
			}
			for (int j = 0; j < lengh2 && test2 == 0; j++) {
				if (word2[j] == key) {
					pos2 = j;
					test2++;
				}
			}
			if (test1 == 0 && test2 == 0) {
				printf("0\n");
				break;
			}
			else {
				if (pos1 > pos2) {
					printf("2\n");
					break;
				}
				else if (pos1 < pos2) {
					printf("1\n");
					break;
				}
				else {
					printf("0\n");
					break;
				}
			}
		}
	}
	free(word1);
	free(word2);
	return 0;
}
