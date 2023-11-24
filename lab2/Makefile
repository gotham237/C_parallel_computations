# kompilator c
CCOMP = gcc

# konsolidator
LOADER = gcc

# opcje optymalizacji:
# wersja do debugowania
 OPT = -g -DDEBUG
# wersja zoptymalizowana do mierzenia czasu
# OPT = -O3

# pliki naglowkowe
INC = -I../pomiar_czasu

# biblioteki
LIB = -L../pomiar_czasu -l pomiar_czasu -lm

# zaleznosci i komendy
fork: fork.o 
	$(LOADER) $(OPT) fork.o -o fork $(LIB)

# jak uzyskac plik fork.o ?
fork.o: fork.c ../pomiar_czasu/pomiar_czasu.h
	$(CCOMP) -c $(OPT) fork.c $(INC) 

# zaleznosci i komendy
clone: clone.o 
	$(LOADER) $(OPT) clone.o -o clone $(LIB)

# jak uzyskac plik clone.o ?
clone.o: clone.c ../pomiar_czasu/pomiar_czasu.h
	$(CCOMP) -c $(OPT) clone.c $(INC) 

clone2: clone2.o 
	$(LOADER) $(OPT) clone2.o -o clone2

clone2.o: clone2.c
	$(CCOMP) -c $(OPT) clone2.c

zad: zad.o 
	$(LOADER) $(OPT) zad.o -o zad

zad.o: zad.c
	$(CCOMP) -c $(OPT) zad.c

wypisz: wypisz.o
	$(LOADER) $(OPT) wypisz.o -o wypisz

wypisz.o: wypisz.c
	$(CCOMP) -c $(OPT) wypisz.c

clean:
	rm -f *.o fork clone clone2 zad
