CC=gcc
CFLAGS=-I ./include/ -O2
CFILES=src/main.c src/lfc/grammar.c
all: bottomup

bottomup: clean
	@echo "Compilazione bottom up parser SLR(1)"
	@$(CC) -o bottomup $(CFILES) $(CFLAGS)
	@echo "Compilazione terminata."

clean:
	@rm -f ./bottomup