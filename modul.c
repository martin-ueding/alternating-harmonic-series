#include "modul.h"

void hallo() {
	printf("Hallo, Welt\n");

	// Versuche 8 GB Speicher zu bekommen.
	size_t n = 1024 * 1024 * 1024;
	int i;
	double *x;
	x = malloc(n * sizeof(double));
	for (i = 0; i < n; ++i) {
		x[i] = i * i;
	}

	printf("%f\n", x[n-1]);
}
