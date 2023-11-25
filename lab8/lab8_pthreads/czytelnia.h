#ifndef _czytelnia_
#define _czytelnia_

/*** Definicje typow zmiennych ***/
typedef struct {
  // <- zasoby czytelni
  int liczba_pisarzy, liczba_czytelnikow;
  pthread_mutex_t mutex;
  pthread_cond_t pisarz;
  pthread_cond_t czytelnik;
  int empty_pisarze, empty_czytelnicy;
} czytelnia_t;

/*** Deklaracje procedur interfejsu ***/
void inicjuj(czytelnia_t* czytelnia_p);
void czytam(czytelnia_t* czytelnia_p);
void pisze(czytelnia_t* czytelnia_p);

int my_read_lock_lock(czytelnia_t* czytelnia_p);
int my_read_lock_unlock(czytelnia_t* czytelnia_p);
int my_write_lock_lock(czytelnia_t* czytelnia_p);
int my_write_lock_unlock(czytelnia_t* czytelnia_p);

#endif
