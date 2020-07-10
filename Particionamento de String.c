/*  
*   Aluno: Natan Henrique Sanches (11795680)
*   ICMC/USP - Bacharelado em Ciências da Computação
*   Particionamento de string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros utilizadas na função printMatrix.
#define NORMAL 1
#define BACKWARDS 2

// Função que encontra o máximo entre dois números. Foi utilizada na função findLongestoWord.
int max(const int n1, const int n2) {
    if(n1 == n2) {return n1;}
    else if(n1 > n2) {return n1;}
    else {return n2;}
}

// Função responsável por contar quantas palavras existem numa string, baseando-se na lógica de que uma palavra possui (número_espaços)+1 palavras.
// O número de palavras da string determinará o número de linhas da matriz em que será particionada a string.
int wordCounter(char *string) {
    int pos = 0;
    int counter = 0;
    do {
        if (string[pos] == ' ') {counter++;}
    } while(string[pos++] != '\0');
    counter += 1;
    return counter;
}

// Função responsável por encontrar o tamanho da maior palavra de toda a string. O tamanho da maior palavra da string determinará o número de
// colunas que a matriz, em que a string será particionada, terá.
int findLongestWord(char *string) {
    int counter = 0;
    int pos = 0;
    int maxvalue = 0;
    do {
        if (string[pos] == ' ') {
            counter = 0;
        } else {
            counter++;
        }
        maxvalue = max(counter, maxvalue);
    } while(string[pos++] != '\0');

    return maxvalue-1;
}

// Função responsável por ler e armazenar dinamicamente uma string a partir do buffer do teclado.
char *readline(FILE *stream) {
    char *string = NULL;
    int pos = 0;
    do {
        string = (char *) realloc(string, (pos+1)*sizeof(char));
        string[pos] = (char) fgetc(stream);
    } while(string[pos++] != '\n' && !feof(stream));
    string[pos-1] = '\0';
    string = (char *) realloc(string, pos);

    return string;
}

// Função responsável por criar uma matriz de dimensão (row)x(col).
char **matrixCreate(const int row, const int col) {
    char **matrix = (char **) malloc(row*sizeof(char *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (char *) calloc(col+1, sizeof(char));
    }

    return matrix;
}

// Função responsável por liberar o espaço alocado para uma matriz.
void freeMatrix(char **matrix, const int row) {
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Função responsável por particionar a string, colocando cada palavra da string em uma linha da matriz.
void arrayToMatrix(char *string, char ***matrix) {
    int pos = 0;
    int row = 0;
    int col = 0;
    do {
        if (string[pos] != ' ') {
            (*matrix)[row][col] = string[pos];
            col += 1;    
        } else {
            row += 1;
            col = 0;
        }
    } while(string[pos++] != '\0');
}

// Função responsável por printar a matriz na tela. A variável command foi necessária por questão de conveniência, uma vez que
// a ordenação, utilizada na operação 2, é feita de trás para frente; assim, é conveniente que se tenha uma maneira de printar
// a matriz também de trás para frente.
void printMatrix(char **matrix, const int row, const int command) {
    switch(command) {
        case NORMAL: {
            for (int i = 0; i < row; i++) {
                printf("%s\n", matrix[i]);
            }
            return;
        }
        case BACKWARDS: {
            for (int i = row-1; i >= 0; i--) {
                printf("%s\n", matrix[i]);
            }
            return;
        }
    }
}

// Função responsável por remover todas as letras maiúsculas iniciais das palavras.
void removeUppercase(char ***matrix, const int row) {
    for (int i = 0; i < row; i++) {
        if ((*matrix)[i][0] >= 'A' && (*matrix)[i][0] <= 'Z')
            (*matrix)[i][0] += 32;
    }
}

// Função responsável por ordenar, em ordem alfabética, as palavras presentes na matriz. A função foi baseada numa espécie de
// "bubble sort" para palavras, visto a simplicidade do algoritmo.
void sortWords(char **matrix, const int row) {
    char *x;
    for (int i = 0; i < row; i++) {
        for (int j = i+1; j < row; j++) {
            if (strcmp(matrix[i], matrix[j]) < 0) {
                x = matrix[j];
                matrix[j] = matrix[i];
                matrix[i] = x;
            }
        }
    }
}

// *string: Variável que armazenará a frase em formato de array. 
// col: Variável que determinará o número de colunas da matriz. O "+1" foi feito para que todas as palavras tenham um terminador de string ao final.
// row: Variável que determinará o número de linhas da matriz, baseado no número de palavras.
// **matrix: Armazenará a *string depois de particionada.
int main(int argc, char *argv[]) {
    char *string = readline(stdin);
    int col = findLongestWord(string)+1;
    int row = wordCounter(string);
    char **matrix = matrixCreate(row, col);

    int operator;
    scanf("%d", &operator);

    switch(operator) {
        case 1: {
            arrayToMatrix(string, &matrix);
            printMatrix(matrix, row, NORMAL);
            break;
        }
        case 2: {
            arrayToMatrix(string, &matrix);
            removeUppercase(&matrix, row);
            sortWords(matrix, row);
            printMatrix(matrix, row, BACKWARDS);
            break;
        }
    }

    free(string);
    freeMatrix(matrix, row);
    return 0;
}
