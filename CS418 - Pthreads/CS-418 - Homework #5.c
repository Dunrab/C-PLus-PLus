#include<stdio.h> //standard library
#include<time.h> //for the timer
#include<stdlib.h> //standard library
#include <pthread.h> //for threads
#include <unistd.h> //for sleep function

//function for threads
void *thread_function(void *arg)
{
         pthread_t pt;
         pt = pthread_self();
         printf("Thread %x ran!\n", (int)pt );
         pthread_exit( NULL );
}
int main()
{
    srand(time(0));
    int i ,j, max1,ret ,status , lowest, highest;
  	int asize = 10000;
    int Num_Threads = 2;
    int a1[asize];
    pthread_t threads[Num_Threads];
    
    for (i = 0; i < 10000; i++)
	{
		a1[i] = rand() % 50000;	
	}
      	
for (i = 0; i <= 10000; i++)
	{
		if (a1[i] < lowest)
		{
			lowest = a1[i];
			
		}
		if (a1[i] > highest)
		{
			highest = a1[i];
		}
		if (highest > 50000)
		{
			highest = 50000;
		}
	}//end of for loop
	
    printf("\n");
	printf("Lowest number in the array: %d ", lowest);
	printf("\n");
	printf("Highest number in the array: %d ", highest);
	printf("\n");
    
    	for (i = 0; i < 10; i++)
	{
		printf("First 10 values in the array: #%d %d \n", i+1, a1[i]);
	}
	
	for (i = 9990; i < 10000; i++)
	{
		printf("Last 10 values in the array: #%d %d \n", i+1, a1[i]);
	}
    
    printf("Sleeping for 5 seconds then using 2 threads: \n");
    sleep(5);
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    for (i = 0 ; i < Num_Threads ; i++)
	{
     ret=pthread_create(&threads[i], NULL, thread_function, &a1[0] );
     if (ret != 0) {
             printf( "Thread ran:  %d\n", (int)threads[i] );
     }
    }
   for (i=0; i<asize/Num_Threads && j<asize; i++,j++)
   {
     ret=pthread_join (threads[i], (void **)&status);
     if (ret != 0) {
             printf( "Thread ran: %d\n", (int)threads[i] );
      } else {
       printf( "Status = %d\n", status );
       }
    }
//    for (i=0; i<asize; i++)
//    {
//       a1[i]= rand()%9;
//    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time it took to run was: %d miliseconds"), cpu_time_used;
	printf("\n");
    
	Num_Threads = 10;
	pthread_t threads10[10];	
  	printf("Sleeping for 5 seconds then using 10 threads: \n");
	sleep(5);
	start = clock();

    for (i = 0 ; i < Num_Threads ; i++)
	{
     ret=pthread_create(&threads[i], NULL, thread_function, &a1[0] );
     if (ret != 0) {
             printf( "Thread ran:  %d\n", (int)threads[i] );
     }
    }
   for (i=0; i<asize/Num_Threads && j<asize; i++,j++)
   {
     ret=pthread_join (threads[i], (void **)&status);
     if (ret != 0) {
             printf( "Thread ran: %d\n", (int)threads[i] );
      } else {
       printf( "Status = %d\n", status );
       }
    }
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time it took to run was: %d miliseconds"), cpu_time_used;
	printf("\n");
	
	Num_Threads = 100;
	pthread_t threads100[100];
	printf("Sleeping for 5 seconds then using 100 threads: \n");
	sleep(5);
	start = clock();//starts the clock
	
	    for (i = 0 ; i < Num_Threads ; i++)
	{
     ret=pthread_create(&threads[i], NULL, thread_function, &a1[0] );
     if (ret != 0) {
             printf( "Thread ran:  %d\n", (int)threads[i] );
     }
    }
   for (i=0; i<asize/Num_Threads && j<asize; i++,j++)
   {
     ret=pthread_join (threads[i], (void **)&status);
     if (ret != 0) {
             printf( "Thread ran: %d\n", (int)threads[i] );
      } else {
       printf( "Status = %d\n", status );
       }
    }
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time it took to run in miliseconds was: %d miliseconds"), cpu_time_used;
	printf(" To find the minimum and maximum values in the array.");
	printf("Threads have ran successfuly!\n");
	printf("\n");

		
return 0;
}
