#include "pthread.h"
#include "stdio.h"
#include <stdlib.h>
void * child_thread (void * param)
{
   time_t t;
srand((unsigned) time(&t));
 int number =  rand() % 10;


return (void *) number;
}

int main()
{
pthread_t thread[5];
int return_value[5];
for(int i=0;i<5;i++)
{
pthread_create(&thread[i],0,&child_thread,0);
}
int sum=0;
for(int i=0;i<5;i++)
{ 
pthread_join(thread[i],(void **)&return_value[i]);
sum+=return_value[i];
}
printf("the sum of thread = %i \n",sum );

}
