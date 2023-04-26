CFLAGS = -Wall -g -std=c99

all: beale

beale: beale.o chaves.o codifica.o decodifica.o liblde.o testa.o
	gcc -o beale beale.o chaves.o codifica.o decodifica.o liblde.o testa.o

beale.o: beale.c
	gcc -c beale.c $(CFLAGS)

chaves.o: chaves.c chaves.h
	gcc -c chaves.c $(CFLAGS)

codifica.o: codifica.c codifica.h
	gcc -c codifica.c $(CFLAGS)

decodifica.o: decodifica.c decodifica.h
	gcc -c decodifica.c $(CFLAGS)

liblde.o: liblde.c liblde.h
	gcc -c liblde.c $(CFLAGS)

testa.o: testa.c testa.h
	gcc -c testa.c $(CFLAGS)

clean:
	-rm *.o

purge:
	-rm *.o beale