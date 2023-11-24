#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "../pomiar_czasu/pomiar_czasu.h"
 
const int liczba = 100000;
const int liczba2 = 10000000;

int main(){

  double a, b, c;
  int i,j,k,l;
  double t1, t2;

  k = -50000;
  inicjuj_czas();
  for(i=0;i<liczba;i++){

    printf("%d ",k+i);

  }
  drukuj_czas();
  printf("\n");


  a = 1.000001;
  t1 = czas_zegara();
  t2 = czas_CPU();
  for(i=0;i<liczba;i++){

    a = 1.000001*a+0.000001; 

  }
  t1 = czas_zegara() - t1;
  t2 = czas_CPU() - t2;
  
  printf("Wynik operacji arytmetycznych: %lf\n", a);
  printf("Czas wykonania %d operacji arytmetycznych: \n",liczba);
  printf("czas CPU         =%lf \n", t2);
  printf("czas zegarowy    =%lf \n", t1);

}
