
openmp_petle_simple: openmp_petle_simple.o 
	gcc -fopenmp -o openmp_petle_simple openmp_petle_simple.o 

openmp_petle_simple.o: openmp_petle_simple.c
	gcc -fopenmp openmp_petle_simple.c -o openmp_petle_simple

clean:
	rm -f *.o openmp_petle_simple
