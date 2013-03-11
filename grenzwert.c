/* Copyright © 2013 Martin Ueding <dev@martin-ueding.de> */

/*
 * Dieses Programm nimmt einen Grenzwert für die alternierende geometrische
 * Reihe entgegen und ordnet die Elemente so um, dass auch wirklich dieser
 * Grenzwert herauskommt.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	double grenzwert;
	double aktuell = 0.0;
	int pos = 1;
	int neg = 2;

	scanf("%f", &grenzwert);

	for (int i = 0; i < 100; i++) {
		if (aktuell < grenzwert) {
			aktuell += 1.0/pos;
			pos += 2;
		}
		else {
			aktuell -= 1.0/neg;
			neg += 2;
		}
		printf("%f\n", aktuell);
	}

	return 0;
}
