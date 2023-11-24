#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  for(int i = 0; i < argc; i++)
  {
      printf("Szymon %s\n", argv[i]);
  }
  printf("PID: %d\n", getpid());

  return 0;
}