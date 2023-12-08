# kompilator c
CCOMP = gcc

# konsolidator
LOADER = gcc

# opcje optymalizacji:
# wersja do debugowania
OPT = -g -DDEBUG  -fopenmp
# wersja zoptymalizowana do mierzenia czasu
# OPT = -O3

# pliki naglowkowe
INC =

# biblioteki
LIB = -lm

# zaleznosci i komendy
openmp_watki_zmienne:openmp_zaleznosci.o 
	$(LOADER) $(OPT) openmp_zaleznosci.o -o openmp_zaleznosci $(LIB)

# jak uzyskac plikopenmp_zaleznosci.o ?
openmp_watki_zmienne.o:openmp_zaleznosci.c
	$(CCOMP) -c $(OPT)openmp_zaleznosci.c $(INC) 

clean:
	rm -f *.o
