/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Cálculo de média harmônica amortizada a partir de n itens
*/

#include <stdio.h>

int main () {
    // n = Número de trabalhos
    // sum = Soma de todos os termos da forma 1/(nota+1)
    // mahf = Média harmônica amortizada final
    int n;
    double sum = 0.0;
    double mahf;

    // Coleta do número de trabalhos
    scanf("%d", &n);

    // Cálculo completo da variável 'sum'
    for (int i = 0; i < n; i++) {
        // nota = Nota do trabalho
        // mah1 = Cálculo do termo 1/(nota+1)
        double nota;
        double mah1;
        scanf("%lf", &nota);
        mah1 = 1/(nota+1);
        sum = sum + mah1;
    }

    //Cálculo da média harmônica final
    mahf = (n/sum)-1;
    printf("%.2lf", mahf);
    return 0;
}