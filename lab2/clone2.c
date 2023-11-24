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

int funkcja_watku( void* argument )
{
  int zmienna_lokalna = *(int*)argument;
  for (int i = 0; i < 1000000; i++) {
    zmienna_lokalna++;
    zmienna_globalna++; 
  }
  printf("Zmienna lokalna: %d, zmienna globalna: %d\n", zmienna_lokalna, zmienna_globalna);
   
  return 0;
}

int main()
{
  void *stos; void *stos1;

  pid_t pid; pid_t pid1;
  int i = 0; 
  
  stos = malloc( ROZMIAR_STOSU );
  stos1 = malloc( ROZMIAR_STOSU );

  if (stos == 0) {
    printf("Proces nadrzędny - blad alokacji stosu\n");
    exit( 1 );
  }
  
  pid = clone( &funkcja_watku, (void *) stos+ROZMIAR_STOSU, 
	CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, &i);
		 
  pid1 = clone( &funkcja_watku, (void *) stos1+ROZMIAR_STOSU, 
	CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, &i);

  waitpid(pid, NULL, __WCLONE);
  waitpid(pid1, NULL, __WCLONE);

  printf("Zmienna globalna w funkcji main: %d\n", zmienna_globalna);

  free( stos );
  free( stos1 );
}