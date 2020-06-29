#include <stdio.h>
#include <math.h>

int main (void) {
	int n;
	double difx, dify;
	double dist;
	double sum = 0.0;

	//Fornecimento de número de pontos
	scanf("%d", &n);
	double x[n], y[n];


	//Fornecimento de coordenadas
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
	}

	//Cálculo da distância total da linha
	for(int j = 0; j < n-1; j++) {
		difx = (x[j+1] - x[j]);
		dify = (y[j+1] - y[j]);
		dist = sqrt(pow(difx,2) + pow(dify,2));
		sum = sum + dist;
	}
	
	printf("%.4lf\n", sum);
	return 0;
}