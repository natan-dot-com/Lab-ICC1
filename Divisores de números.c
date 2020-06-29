/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Verificar quais números contidos dentro de um vetor de 31 índices é divisível pelo último número armazenado nesse vetor
*/

#include <stdio.h>

int main (void) {
    // Recebimento dos 31 números
    int num[31];
    // Entrada de dados
    for (int i = 0; i < 31; i++) {
        scanf("%d", &num[i]);
    }
    // Verificação se num[j] é divisível pelo último número informado
    for (int j = 0; j < 30; j++) {
        if (num[j] % num[30] == 0) {
            printf("%d\n", num[j]);
        }
    }
    return 0;
}