#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include<pthread.h>
#include <unistd.h>

#define ILE_MUSZE_WYPIC 1000

void * watek_klient (void * arg);

int l_kf;

pthread_mutex_t mutex;

int main( void ){

  pthread_mutex_init(&mutex, NULL);

  pthread_t *tab_klient;
  int *tab_klient_id;

  int l_kl, l_kr, i;


  printf("\nLiczba klientow: "); scanf("%d", &l_kl);

  printf("\nLiczba kufli: "); scanf("%d", &l_kf);

  //printf("\nLiczba kranow: "); scanf("%d", &l_kr);
  l_kr = 1000000000; // wystarczajÄco duĹźo, Ĺźeby nie byĹo rywalizacji 

  tab_klient = (pthread_t *) malloc(l_kl*sizeof(pthread_t));
  tab_klient_id = (int *) malloc(l_kl*sizeof(int));
  for(i=0;i<l_kl;i++) tab_klient_id[i]=i;


  printf("\nOtwieramy pub (simple)!\n");
  printf("\nLiczba wolnych kufli %d\n", l_kf); 

  for(i=0;i<l_kl;i++){
    pthread_create(&tab_klient[i], NULL, watek_klient, &tab_klient_id[i]); 
  }
  for(i=0;i<l_kl;i++){
    pthread_join( tab_klient[i], NULL);
  }
  printf("Liczba kufli po zakonczeniu pracy: %d\n", l_kf);
  printf("\nZamykamy pub!\n");
}


void * watek_klient (void * arg_wsk){

  int moj_id = * ((int *)arg_wsk);

  int i, j, kufel, result;
  int ile_musze_wypic = ILE_MUSZE_WYPIC;

  long int wykonana_praca = 0;

  printf("\nKlient %d, wchodzi do pubu\n", moj_id); 
  
   for(i=0; i<ile_musze_wypic; i++){
    for(;;) {
      pthread_mutex_lock(&mutex);
      if (l_kf > 0) {
        l_kf--;
        printf("\nKlient %d, wybieram kufel\n", moj_id);
        break;
      }
      else {
        pthread_mutex_unlock(&mutex);
        usleep(20);
      }
    }
    pthread_mutex_unlock(&mutex);
    printf("\nKlient %d, odkladam kufel\n", moj_id);

    pthread_mutex_lock(&mutex);
    l_kf++;
    pthread_mutex_unlock(&mutex);

    return(NULL);
  }
}
