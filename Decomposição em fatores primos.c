/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Decomposição de números em fatores primos
*
*	Lógica utilizada na construção do exercício:
*	Foi feito um mecanismo para detectar se cada número, a partir de 2, é primo. Se a resposta for afirmativa, o laço prossegue para dividir
*	o número de entrada o máximo de vezes possível por esse primo e contabilizá-lo; caso o número de entrada não seja divisível pelo primo, o
*	laço de repetição avança para o teste do próximo número primo. Se a resposta for negativa, o laço avança para o teste do próximo número
*	primo.
*/

#include <stdio.h>

int main () {
    // n = Número natural de entrada
    // div = Auxiliar para detectar se o número é primo
    // j = Variável pela qual os números primos irão passar
    int n;
    int div = 0;
    int j;

    // Entrada
    scanf("%d", &n);

    // Início do laço de decomposição do número n
    for (j = 2; n != 1;) {
    	// Laço de teste para checar se j é primo
    	for (int k = 1; k <= j; k++) {
    		if (j % k == 0) {
    			div++;
    		}
    	}
    	// Em caso afirmativo (div == 2 implica que j é divisível por 1 e por ele mesmo, apenas)	
	   	if (div == 2) {
	    	// div2 = Contador de quantas vezes n foi dividido pelo primo j
	    	int div2 = 0;
	    	// Decomposição de n pelo primo j
	    	while (n % j == 0) {
	  	 		int op;
	   			op = n / j;
	   			div2++;
	   			n = op;
	   		}
	   		// Se o número não for divisível pelo primo j encontrado (implica div2 == 0)
	   		if (div2 == 0) {
    			div = 0;
	    		j++;
	    	// Se o número for divisível pelo primo j (implica div2 != 0)
	   		} else {
	   			printf("%d %d\n", j, div2);
	   			div = 0;
	   			div2 = 0;
	   			j++;
	   		}
	   	// Caso j não seja primo
    	} else {
    		div = 0;
    		j++;
    	}
   	}
    return 0;
}