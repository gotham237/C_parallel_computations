#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

#define THREADS_NUMBER 10

void* fun(void* arg)
{
  int system_ID = pthread_self();
  int thread_ID = *((int*)arg);
  printf("system ID: %d, przeslane ID: %d \n", system_ID, thread_ID);
  return (NULL);
 }


int main()
{
  int i;
  pthread_t tid[THREADS_NUMBER] = {0};
  int thread_ID[THREADS_NUMBER] = {0};

  for(i = 0; i < THREADS_NUMBER; i++)
  {
    //sleep(0.5);
    thread_ID[i] = i;
    pthread_create(&tid[i], NULL, fun, &i);
  }

  for(i = 0; i < THREADS_NUMBER; i++)
  {
    pthread_join(tid[i], NULL);
  }

}