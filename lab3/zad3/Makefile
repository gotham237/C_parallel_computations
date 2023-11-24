# kompilator c
CCOMP = gcc

# konsolidator
LOADER = gcc

# opcje optymalizacji:
# wersja do debugowania
 OPT = -g -DDEBUG
# wersja zoptymalizowana do mierzenia czasu
# OPT = -O3

# zaleznosci i komendy
zad3: zad3.o 
	$(LOADER) $(OPT) zad3.o -o zad3 

zad3.o: zad3.c
	$(CCOMP) -c $(OPT) zad3.c 

clean:
	rm -f *.o zad3