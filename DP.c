#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

pthread_t philosopher[5];
pthread_mutex_t chopstick[5];

void *func(int n)
   {
      int thread = (intptr_t) n;
   printf ("Philosopher %d is thinking\n",thread);

   //when philosopher 5 is eating he takes fork 1 and fork 5
   pthread_mutex_lock(&chopstick[thread]);
   pthread_mutex_lock(&chopstick[(thread+1)%5]);
   printf ("Philosopher %d is eating\n",thread);
   //sleep(3);
   pthread_mutex_unlock(&chopstick[thread]);
   pthread_mutex_unlock(&chopstick[(thread+1)%5]);

   printf ("Philosopher %d finished eating\n",thread);

   return(NULL);
   }

int main()
   {
   int i;
   for(i=0;i<5;i++)
      pthread_mutex_init(&chopstick[i],NULL);

   for(i=0;i<5;i++)
      pthread_create(&philosopher[i],NULL,(void *)func,(void *)(intptr_t)i);

   for(i=0;i<5;i++)
      pthread_join(philosopher[i],NULL);

   for(i=0;i<5;i++)
      pthread_mutex_destroy(&chopstick[i]);

   return 0;
   }
