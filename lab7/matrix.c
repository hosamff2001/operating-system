
#include "pthread.h"
#include "stdio.h"
#include <stdlib.h>

// maximum size of matrix

#define MAX 10
 
// maximum number of threads
#define MAX_THREAD 10
 
int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;
  int size_matrix=0;
void* multi(void* arg)
{
    int i = step_i++; //i denotes row number of resultant matC
   
    for (int j = 0; j < size_matrix; j++)
      for (int k = 0; k < size_matrix; k++)
        matC[i][j] += matA[i][k] * matB[k][j];
}
 
// Driver Code
int main()
{
   
    printf("enter size of matrix (max 10) =");
    scanf("%d",&size_matrix);

    // Generating random values in matA and matB
    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++) {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }
 
    // Displaying matA
        printf("\n Matrix A \n");
    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++)
             printf("%d ", matA[i][j]);  
        printf("\n");
    }
 
    // Displaying matB
    printf("\n Matrix B \n");
    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++)
       printf("%d ", matB[i][j] );      
    printf("\n");
    }
 
    // declaring four threads
    pthread_t threads[MAX_THREAD];
 
    // Creating four threads, each evaluating its own part
    for (int i = 0; i < MAX_THREAD; i++) {
        int* p;
        pthread_create(&threads[i], NULL, multi, (void*)(p));
    }
 
    // joining and waiting for all threads to complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);   
 
    // Displaying the result matrix
printf("\n Multiplication of A and B \n");

    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++)
               printf("%d ", matC[i][j]);             
        printf("\n");
    }
    return 0;
}
