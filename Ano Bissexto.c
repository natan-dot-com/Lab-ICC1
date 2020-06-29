#include <stdio.h>

int main(void) {
    int ano, r;
    scanf("%d", &ano);
    
    //Encontro do resto
    r = ano%4;

    if (r == 0) {
        printf("SIM");
    }
    else {
        printf("NAO");
    }

    return 0;
}
