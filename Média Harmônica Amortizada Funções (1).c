/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Cálculo da média harmônica com uso de funções de entrada/saída
*/
#include <stdio.h>

// Função para leitura de inteiro
int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}
// Função para leitura de um real
double readDouble() {
    double real;
    scanf("%lf", &real);
    return real;
}
// Função para a impressão de algum parâmetro val
double printDouble (double val) {
    printf("%.2lf", val);
    return val;
}

int main (void) {
    // Entrada do número de trabalhos
    int n = readInt();
    
    // real = Nota respectiva do trabalho
    // sum = Soma das operações do denominador da média harmônica amortizada
    double real;
    double sum = 0;
    
    // Entrada dos n valores das notas e cálculo de sum
    for (int i = 0; i < n; i++) {
        real = readDouble();
        double op1 = 1/(real+1);
        sum += op1;
    }

    // mah = Cálculo final da média harmônica amortizada
    double mah;
    mah = (n/sum)-1;
    
    // Saída da média harmônica amortizada
    printDouble (mah);
    return 0;
}