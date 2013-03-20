# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

# Compiler wählen und Flags setzen.
CC = gcc
CFLAGS = -O3 -Wall -std=c99 -pedantic -g

# Suche alle Dateien raus und generiere aus jedem `.c` ein `.o`.
cfiles = $(wildcard *.c)
ofiles = $(cfiles:.c=.o)

# Das Programm hängt von folgenden `.o` ab:
grenzwert: $(ofiles)

# Dies lässt `make dep` durch `gcc` die Abhängigkeiten aller `.c` Dateien finden und als makefile ausgeben.
dep:
	$(CC) -MM *.c > dep.makefile

# Importiere die makefile.
-include dep.makefile

.PHONY: clean
clean:
	$(RM) grenzwert
