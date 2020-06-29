#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, ab;

    //Primeiro número
    scanf("%f", &a);
    //Segundo número
    scanf("%f", &b);

    //Potência
    ab = pow(a,b);
    printf("%.4f", ab);
    
    return 0;
}
