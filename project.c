#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t l;
/*
enum directions{
                east=1,west=2,north=3,south=4
};
*/
// purpose of the generating the random number we just asssuming the random number as a direction
static int origin1,destination1;
static int origin2,destination2;

void *vehicle1()
{  
   pthread_mutex_lock(&l);
   origin1=rand()%4;
   destination1=rand()%4;    //generates the random direction which is assuming as a random direction

   if(origin1==origin2 ||destination1==destination2)
    {
     printf("Vehicle2 is entering in critical section\n");
     sleep(1);
    }
    else if(origin1==destination2 ||origin2==destination1)
    {
      printf("Vehicle 2 is entering in critical section\n");
      sleep(1);
    }
    else if(origin1==origin2  ||destination1!=destination2)
   {
     printf("Vehicle 2 is entering in critical secition\n");
     sleep(1);
   }
    else{
         printf("Vehicle 1 and 2 are colliding ");  
      } 
   pthread_mutex_unlock(&l);

}

void *vehicle2()
{
 
  pthread_mutex_lock(&l);
  origin2=rand()%4;
  destination2=rand()%4;
  if(origin1==origin2  ||destination1==destination2)
  {
   printf("Vehicle1 is entering in critical section\n");
   sleep(1);
  }
  else if(origin1==destination2 || origin2==destination1)
  {
    printf("Vehicle 1 is entering in crical section\n");
    sleep(1);
  }
  else if(origin1==origin2 ||destination1!=destination2)
  {
    printf("Vehicle 1 is entering in crical section\n");
    sleep(1);
  }
  else{
    printf("Vehicle 1 and 2 are colliding!!!");
   }
  pthread_mutex_unlock(&l);
  
}
int main()
{
  pthread_mutex_init(&l,NULL);       //we don't share any shared variable with the fork
 
  pthread_t p,q;

  pthread_create(&p,NULL,vehicle1,NULL);
  pthread_create(&q,NULL,vehicle2,NULL);

  pthread_join(p,NULL);
  pthread_join(q,NULL);
 
}
