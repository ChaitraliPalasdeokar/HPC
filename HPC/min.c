#include <stdio.h>
#include <omp.h>

int main()
{
  double arr[10];
  omp_set_num_threads(4);
  double min_val=9.0;
  int i;
  for( i=0; i<10; i++)
     arr[i] = 2.0 + i;
  #pragma omp parallel for reduction(min : min_val)
  for( i=0;i<10; i++)
  {
     printf("thread id = %d and i = %d \n", omp_get_thread_num(),i); 
     if(arr[i] < min_val)
     {
        min_val = arr[i];
     }
  }
  printf("\nmin_val = %f", min_val);
}

Output:
bvcoew@bvcoew-ThinkCentre-E73:~$ g++ min.c -fopenmp
bvcoew@bvcoew-ThinkCentre-E73:~$ ./a.out
thread id = 2 and i = 6 
thread id = 2 and i = 7 
thread id = 0 and i = 0 
thread id = 0 and i = 1 
thread id = 0 and i = 2 
thread id = 3 and i = 8 
thread id = 3 and i = 9 
thread id = 1 and i = 3 
thread id = 1 and i = 4 
thread id = 1 and i = 5 

min_val = 2.000000
