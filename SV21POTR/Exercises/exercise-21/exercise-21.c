#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Beskrivning
Make a program to fill a 2D array (3x3) of type int with random
numbers in the range of 0 and 99 and then print the array to the terminal.
To fill and print the array, use only pointers.
*/

#define SIZE1 2 // rows
#define SIZE2 3 // columns

int main()
{
    int arr[SIZE1][SIZE2];
    
    // randomize
    srand(time(NULL));
    for (int i=0; i<SIZE1; i++)
    for (int j=0; j<SIZE2; j++)
        *(*(arr+i)+j) = rand() % 100;
    
    // print using pointers
    printf("Matrix (using **):\n");
    for (int i=0; i<SIZE1; i++)
    {
        for (int j=0; j<SIZE2; j++)
            printf("%4d", *(*(arr+i)+j));

        printf("\n");
    }

    // print using index to TEST that the answer is correct and equivalent
    printf("Matrix (using [][]):\n");

    for (int i=0; i<SIZE1; i++)
    {
        for (int j=0; j<SIZE2; j++)
            printf("%4d", arr[i][j]);

        printf("\n");
    }

    return 0;
}