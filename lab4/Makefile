# kompilator c
CCOMP = gcc

# konsolidator
LOADER = gcc

# opcje optymalizacji:
# wersja do debugowania
# OPT = -g -DDEBUG
# wersja zoptymalizowana do mierzenia czasu
# OPT = -O3
OPT = -O0 -g

# zaleznosci i komendy
pub_sym_1: pub_sym_1.o 
	$(LOADER) $(OPT) pub_sym_1.o -o pub_sym_1 

# jak uzyskac plik pub_sym_1.o ?
pub_sym_1.o: pub_sym_1.c
	$(CCOMP) -c $(OPT) pub_sym_1.c 

pub_sym_1_2.o: pub_sym_1_2.o 
	$(LOADER) $(OPT) pub_sym_1_2.o -o pub_sym_1_2 

# jak uzyskac plik pub_sym_1_2.o ?
pub_sym_1_2.o: pub_sym_1_2.c
	$(CCOMP) -c $(OPT) pub_sym_1_2.c 

clean:
	rm -f *.o pub_sym_1 pub_sym1_2
