/* Copyright © 2013 Martin Ueding <dev@martin-ueding.de> */

/**
 * Dieses Programm nimmt einen Grenzwert für die alternierende geometrische
 * Reihe entgegen und ordnet die Elemente so um, dass auch wirklich dieser
 * Grenzwert herauskommt.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	float grenzwert;
	float aktuell = 0.0;

	// Aktueller Stand für die positiven und negativen Elemente der Reihe. Die
	// Umordnung zieht nur gerade und ungerade Elemente nach vorne, sortiert
	// diese allerdings nicht noch weiter um. Daher wird hier nicht mehr
	// gebraucht als der zuletzt benutzte Nenner.
	int pos = 1;
	int neg = 2;

	// Lese eine Fließkommazahl vom Benutzer ein. Dabei wird darauf geachtet,
	// dass `scanf` auch wirklich eine Zahl findet. Falls nicht, wird das
	// Programm hier abgebrochen.
	printf("Gewünschter Grenzwert: ");
	if (scanf("%f", &grenzwert) != 1) {
		// Wenn das Programm hier angekommen ist, konnte `scanf` nicht genau
		// einen Wert entgegen nehmen. Daher muss hier abgebrochen werden.
		printf("Bitte eine Zahl eingeben!\n");

		// Ein Rückgabewert, der ungleich 0 ist, bedeutet, dass etwas schief
		// gelaufen ist.
		return 1;
	}

	// Gehe einige Folgenglieder durch …
	for (int i = 0; i < 30; i++) {
		// Falls der aktuelle Wert unterhalb des Grenzwertes liegt, addiere ein
		// positives Folgenglied auf.
		if (aktuell < grenzwert) {
			aktuell += 1.0/pos;
			// Gib das zuletzt benutzte Folgenglied aus, sowie den aktuellen
			// Grenzwert.
			printf("+ 1/%3d, aktuell: %8f\n", pos, aktuell);
			// Gehe zum nächsten Folgenglied.
			pos += 2;
		}
		// Falls der aktuelle Wert zu groß ist, addiere ein negatives
		// Folgenglied.
		else {
			aktuell -= 1.0/neg;
			// Gib das zuletzt benutzte Folgenglied aus, sowie den aktuellen
			// Grenzwert.
			printf("- 1/%3d, aktuell: %8f\n", neg, aktuell);
			// Gehe zum nächsten Folgenglied.
			neg += 2;
		}
	}

	// Alles okay, gebe 0 zurück.
	return 0;
}
