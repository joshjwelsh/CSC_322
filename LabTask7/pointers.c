#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 5

void outputArray(int size, int myArray[]){

    for (int i = 0; i < size; i++)
    {
        printf("%d : %d\n", i, myArray[i]);
    }
}

void pOutputArray(int * pArray){
    int *p;
    int count = 0;
    printf("--- Pointers ---- \n");
    p = pArray;
     for (count = 0; count < SIZE; count++)
    {

        printf("%d : %d\n", count, *p);
        p++;

    }
}

int * bubbleSort(int pArray[]){
    int i,j;
    int * temp;
    for(i = 0; i < SIZE; i++){
       for(j = 0; j < SIZE-i-1; j++) {
           if(pArray[j] > pArray[j+1]){
                *temp = pArray[j];
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = *temp;
           }
       }
    }
    return pArray;
}

void bubbleSortPointers(int * pArray){
    int *ptr, *temp; 
    int i, j;
    ptr = pArray;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE-i-1; j++){
            if( *(ptr + j) > *(ptr + j + 1) ){
                *temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = *temp;
             }
        }
    }
}

int main(void){

    int age = 20;
    int nArray[SIZE];
    int * pnArray[SIZE];
    int *ptr;
    size_t i;
    srand(getpid());

    printf("--- Initialized array of integers ---\n");
    for(i = 0; i < SIZE;i++){
        nArray[i] = rand();
    }


    outputArray(SIZE,nArray);

    for(i = 0; i < SIZE; i++){
        pnArray[i] = &nArray[i];
    }

    pOutputArray(*pnArray);
    printf("--- Sorted array of integers ---\n");
    outputArray(SIZE, bubbleSort(nArray));
    bubbleSortPointers(*pnArray);

    printf("--- Sorted array of pointers ---\n");
    pOutputArray(*pnArray);

    return 0;
}