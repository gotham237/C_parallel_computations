#define _GNU_SOURCE
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>
#include <linux/sched.h>

int zmienna_globalna=0;

#define ROZMIAR_STOSU 1024*64

int funkcja_watku()
{
  int wynik;
  char* args[] = {"Tymula", NULL};
  wynik=execv("./wypisz", args);
  if(wynik == -1)
  {
    printf("Proces potomny nie wykonał programu\n");
    exit(1);
  }
  return 0;
}

int main(int argc, char *argv[])
{

  void *stos; void *stos1;

  pid_t pid; pid_t pid1;
  int i = 0; 
  
  stos = malloc( ROZMIAR_STOSU );
  stos1 = malloc( ROZMIAR_STOSU );

  if (stos == 0 || stos1 == 0) {
    printf("Proces nadrzędny - blad alokacji stosu\n");
    exit( 1 );
  }
  for(i = 0; i < 1000; i++) 
  {
  pid = clone( &funkcja_watku, (void *) stos+ROZMIAR_STOSU, 
	CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
		 
  pid1 = clone( &funkcja_watku, (void *) stos1+ROZMIAR_STOSU, 
	CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);

  waitpid(pid, NULL, __WCLONE);
  waitpid(pid1, NULL, __WCLONE);
  }
  
  free( stos );
  free( stos1 );
}