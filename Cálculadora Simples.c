#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    double a, b;
    char op;
    double result;

    scanf("%lf %c %lf", &a, &op, &b);

    switch (op) {
        case '+' :
            result = a+b;
            printf("%lf", result);
            break;

        case '-' :
            result = a-b;
            printf("%lf", result);
            break;

        case '*' :
            result = a*b;
            printf("%lf", result);
            break;

        case '/' :
        if (b == 0)
            break;    
        else {    
            result = a/b;
            printf("%lf", result);
            break;
        }

        case '%' :
        if (b == 0)
            break;
        else {
            result = (a/b)*100;
            printf("%lf", result);
            break;
        }
    }
    return 0;
}