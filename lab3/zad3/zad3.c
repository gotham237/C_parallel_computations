#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

struct struktura_t { int a; double b; char d; };
void * zadanie_watku (void * arg_wsk);

int main()
{
  pthread_t tid, tid1;
  struct struktura_t struktura_main = { 3, 3.141234, 'd' };
  pthread_create(&tid, NULL, zadanie_watku, &struktura_main);
  pthread_create(&tid1, NULL, zadanie_watku, &struktura_main);
  pthread_join( tid, NULL);
  pthread_join( tid1, NULL);

  printf("Struktura w main: a = %d, b = %lf, d = %c\n", struktura_main.a, struktura_main.b, struktura_main.d);
}

void * zadanie_watku (void * arg_wsk)
{
  struct struktura_t *wskaznik_do_struktury_main = arg_wsk;
  struct struktura_t struktura_lokalna;

  struktura_lokalna = *( (struct struktura_t *) arg_wsk );

  struktura_lokalna.a += 2;
  struktura_lokalna.b += 2;
  struktura_lokalna.d += 2;

  wskaznik_do_struktury_main->a += 2;
  wskaznik_do_struktury_main->b += 2;
  wskaznik_do_struktury_main->d += 2;

  printf("Dostep do wartosci z procedury main: a = %d, b = %lf, d = %c\n",
    wskaznik_do_struktury_main->a, wskaznik_do_struktury_main->b, wskaznik_do_struktury_main->d);
  printf("Dostep do skopiowanych lokalnych wartosci: a = %d, b = %lf, d = %c\n",
    struktura_lokalna.a, struktura_lokalna.b, struktura_lokalna.d);
  
  return(NULL);
}
