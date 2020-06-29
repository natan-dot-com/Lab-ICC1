#include <stdio.h>

int main () {
    double a, b, c, d;
    double min;
    double media;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);

    if (a < b)
        min = a;
    else if (b < c)
        min = b;
    else if (c < d)
        min = c;
    else
        min = d;

    media = (a + b + c + d - min) / 3;
    printf("%.4lf", media);

    return 0;
}
