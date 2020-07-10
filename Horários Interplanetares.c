/*
*	Aluno: Natan Henrique Sanches (11795680)
*	ICMC/USP - Bacharelado em Ciências da Computação
*	Horários Interplanetares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printResult(unsigned long long *planet_time, unsigned long long sec, char *planet) {
    printf("%llu segundos no planeta %s equivalem a:\n", sec, planet);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", planet_time[0], planet_time[1], planet_time[2], planet_time[3]);
}

// Conversor para horário terrestre.
void timeInEarth(unsigned long long **planet_time, unsigned long long sec) {
    if (sec >= 86400) {					// Um dia na Terra equivale a 86400 segundos
        (*planet_time)[0] = sec/86400;
        sec %= 86400;
    }
    if (sec >= 3600) {					// Uma hora equivale a 3600 segundos  
        (*planet_time)[1] = sec/3600;
        sec %= 3600;
    }
    if (sec >= 60) {					// Um minuto equivale a 60 segundos					
        (*planet_time)[2] = sec/60;
        sec %= 60; 
    }
    (*planet_time)[3] = sec;
}

// Conversor para horário em Vênus.
void timeInVenus(unsigned long long **planet_time, unsigned long long sec) {
	int DayInVenus = 243*24;			// Um dia em Vênus possui 243*24 *horas* terrestres 
	(*planet_time)[0] = (sec/3600) / DayInVenus;	// A divisão do número de horas em Vênus pela duração do dia nos dá o número de dias em Vênus
	(*planet_time)[1] = (sec/3600) % DayInVenus;	// O resto da divisão acima nos dá o número de horas em Vênus desconsiderando os dias
	(*planet_time)[2] = (sec/60) % 60;  
	(*planet_time)[3] = sec % 60;
}

// Conversor para horário em Mercúrio.
void timeInMercury(unsigned long long **planet_time, unsigned long long sec) {
	int DayInMercury = 86400*58 + 3600*16;		 // Um dia em Mercúrio possui 86400*58 + 3600*16 *segundos* terrestres
	(*planet_time)[0] = sec/DayInMercury;		 // A divisão do número de segundos em Mercúrio pela duração do dia nos dá o número de dias			
	(*planet_time)[1] = (sec%DayInMercury) / 3600;	 // O resto da divisão acima, convertida em horas, nos dá o número de horas em Mercúrio
	(*planet_time)[2] = (sec%DayInMercury/60) % 60;
	(*planet_time)[3] = sec % 60;
}

// Conversor para horário em Júpiter
void timeInJupiter(unsigned long long **planet_time, unsigned long long sec) {
	int DayInJupiter = 3600*9 + 60*56;		 // Um dia em Júpiter possui 3600*9 + 60*56 *segundos* terrestres 
	(*planet_time)[0] = sec/DayInJupiter;		 // A divisão do número de segundos em Júpiter pela duração do dia nos dá o número de dias 
	(*planet_time)[1] = (sec%DayInJupiter) / 3600;	 // O resto da divisão acima, depois de convertida em horas, devolve o número de horas no planeta
	(*planet_time)[2] = (sec%DayInJupiter/60) % 60;
	(*planet_time)[3] = sec % 60;
}

int main(int argc, char *argv[]) {
    unsigned long long  sec;
    unsigned long long *planet_time;
    char *planet = (char *) calloc(12, sizeof(char));
    scanf("%llu %s", &sec, planet);

    planet_time = (unsigned long long *) calloc(4, sizeof(unsigned long long));

	if(!strcmp(planet, "Terra")) {
		timeInEarth(&planet_time, sec);
		printResult(planet_time, sec, planet);

	} else if (!strcmp(planet, "Venus")) {
		timeInVenus(&planet_time, sec);
		printResult(planet_time, sec, planet);

	} else if (!strcmp(planet, "Mercurio")) {
		timeInMercury(&planet_time, sec);
		printResult(planet_time, sec, planet);

	} else if (!strcmp(planet, "Jupiter")) {
		timeInJupiter(&planet_time, sec);
		printResult(planet_time, sec, planet);
	}
    
	free(planet);
	free(planet_time);
    return 0;
}
