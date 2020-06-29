/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Exibir maior e menor número de uma lista de n números
*/

#include <stdio.h>

int main (void) {
    // n = Número de inteiros de entrada
    // max = Valor máximo / min = Valor mínimo
    int n;
    int max, min;
    scanf("%d", &n);

    // Coleta dos n números inteiros
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    // Algoritmo de ordenação (bubble sort)
    for (int cont = 1; cont < n; cont++) {
        for (int j = 0; j < n-1; j++) {
            if (num[j] > num[j+1]) {
                int temp;
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }

    // Atribuição de max, min
    max = num[n-1];
    min = num[0];
    printf("max: %d\nmin: %d", max, min);
    return 0;
}