/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Expoente com laço de repetição
*/

#include <stdio.h>

int main () {
    // a = Número real qualquer
    // b = Potência do número real
    double a;
    int b;
    double exp = 1;

    //Coleta de dados de entrada
    scanf("%lf", &a);
    scanf("%d", &b);

    //Cálculo da multiplicação sequencial
    for (int i = 0; i < b; i++) {
        exp = exp*a;
    }

    printf("%.4lf", exp);
    return 0;
}