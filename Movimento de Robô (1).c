/*
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências de Computação
*   Movimento do robô
*/

#include <stdio.h>
#include <string.h>

int main (void) {
    // comandos[201] = String de comandos
    char comandos[201];
    scanf("%s", comandos);

    // tamanho = Tamanho da string comandos
    // clock = Valor que acompanhará a rotação do robô
    int tamanho = strlen(comandos);
    int clock = 0;

    // Processo de rotação, considerando sentido horário como positivo
    for (int i = 0; i < tamanho; i++) {
        if (comandos[i] == 'D') {
            clock++;
        } 
        else if (comandos[i] == 'E') {
            clock--;
        }
    }

    // resto = Resto da divisão de clock por 4, descartando as voltas repetidas
    int resto = clock % 4;
    
    // O resto determinará que posição o robô permaneceu ao dar clock/4 voltas e ter acabado os comandos
    // Clock positivo -> resto positivo
    if (clock >= 0) {
        switch (resto) {
            case 0 :
                printf("Norte");
                break;
            case 1 :
                printf("Leste");
                break;
            case 2 :
                printf("Sul");
                break;
            case 3 :
                printf("Oeste");
                break;
        }
    }
    // Clock negativo -> resto negativo
    else if (clock < 0) {
        switch (resto) {
            case 0 :
                printf("Norte");
                break;
            case -1 :
                printf("Oeste");
                break;
            case -2 :
                printf("Sul");
                break;
            case -3 :
                printf("Leste");
                break;
        }
    }
    return 0;
}