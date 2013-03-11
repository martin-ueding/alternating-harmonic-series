# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

CC = gcc
CFLAGS = -O3 -Wall -std=c99 -pedantic

grenzwert: grenzwert.c

.PHONY: clean
clean:
	$(RM) grenzwert
