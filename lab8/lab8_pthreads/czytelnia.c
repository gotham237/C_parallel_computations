#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#include"czytelnia.h"


/*** Implementacja procedur interfejsu ***/

int my_read_lock_lock(czytelnia_t* czytelnia_p){
  pthread_mutex_lock(&czytelnia_p -> mutex);

  if((czytelnia_p -> liczba_pisarzy > 0) || (czytelnia_p -> empty_pisarze != 0)) {
    czytelnia_p -> empty_czytelnicy++;
    pthread_cond_wait(&czytelnia_p -> czytelnik, &czytelnia_p -> mutex);
    czytelnia_p -> empty_czytelnicy--;
  }

  czytelnia_p -> liczba_czytelnikow++;

  pthread_cond_signal(&czytelnia_p -> czytelnik);

  pthread_mutex_unlock(&czytelnia_p -> mutex);
}


int my_read_lock_unlock(czytelnia_t* czytelnia_p){
  pthread_mutex_lock(&czytelnia_p -> mutex);
  czytelnia_p -> liczba_czytelnikow--;
  pthread_mutex_unlock(&czytelnia_p -> mutex);

  if(czytelnia_p -> liczba_czytelnikow == 0) 
    pthread_cond_signal(&czytelnia_p -> pisarz);
}


int my_write_lock_lock(czytelnia_t* czytelnia_p){
  pthread_mutex_lock(&czytelnia_p -> mutex);

  if(czytelnia_p -> liczba_pisarzy > 0 || czytelnia_p -> liczba_czytelnikow > 0){
    czytelnia_p -> empty_pisarze++;
    pthread_cond_wait(&czytelnia_p -> pisarz, &czytelnia_p ->mutex);
    czytelnia_p -> empty_pisarze--;
  }

  czytelnia_p -> liczba_pisarzy++;

  pthread_mutex_unlock(&czytelnia_p -> mutex);
}


int my_write_lock_unlock(czytelnia_t* czytelnia_p){
  pthread_mutex_lock(&czytelnia_p -> mutex);
  czytelnia_p -> liczba_pisarzy--;
  
  if(czytelnia_p -> empty_czytelnicy != 0){
    czytelnia_p->empty_czytelnicy--;
    pthread_cond_signal(&czytelnia_p -> czytelnik);
  }
  else
  {
    pthread_cond_signal(&czytelnia_p -> pisarz);
  }

  pthread_mutex_unlock(&czytelnia_p -> mutex);
}

void inicjuj(czytelnia_t* czytelnia_p){
  pthread_mutex_init(&czytelnia_p -> mutex, NULL);
  pthread_cond_init(&czytelnia_p -> pisarz, NULL);
  pthread_cond_init(&czytelnia_p -> czytelnik, NULL);
}

void czytam(czytelnia_t* czytelnia_p){

// wypisanie wartości zmiennych kontrolujących działanie: liczby czytelników i pisarzy
  printf("Czytelnicy: %d, pisarze: %d\n", czytelnia_p -> liczba_czytelnikow, czytelnia_p -> liczba_pisarzy);
// sprawdzenie warunku poprawności i ewentualny exit
// warunek: if( l_p>1 || (l_p==1 && l_c>0) || l_p<0 || l_c<0 ) { printf(...); exit(0); }
  if (czytelnia_p -> liczba_pisarzy > 1 || (czytelnia_p -> liczba_pisarzy == 1 && czytelnia_p -> liczba_czytelnikow > 0) ||
    czytelnia_p -> liczba_pisarzy < 0 || czytelnia_p -> liczba_czytelnikow < 0) {
    printf("Nie spelniono warunkow.");
    exit(0);
  }
    usleep(rand()%300000);
}

void pisze(czytelnia_t* czytelnia_p){

// wypisanie wartości zmiennych kontrolujących działanie: liczby czytelników i pisarzy
  printf("Czytelnicy: %d, pisarze: %d\n", czytelnia_p -> liczba_czytelnikow, czytelnia_p -> liczba_pisarzy);
// sprawdzenie warunku poprawności i ewentualny exit
// warunek: if( l_p>1 || (l_p==1 && l_c>0) || l_p<0 || l_c<0 ) { printf(...); exit(0); }
  if (czytelnia_p -> liczba_pisarzy > 1 || (czytelnia_p -> liczba_pisarzy == 1 && czytelnia_p -> liczba_czytelnikow > 0) ||
    czytelnia_p -> liczba_pisarzy < 0 || czytelnia_p -> liczba_czytelnikow < 0) {
    printf("Nie spelniono warunkow.");
    exit(0);
  }

    usleep(rand()%300000);
}


