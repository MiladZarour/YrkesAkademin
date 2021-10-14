#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Beskrivning
Make a program to fill a 2D array (3x3) of type int with random
numbers in the range of 0 and 99 and then print the array to the terminal.
To fill and print the array, use only pointers.
*/


int main()
{
    int arr[3][3];
    
    // randomize
    srand(time(NULL));
    for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
        *(*(arr+i)+j) = rand() % 100;
    
    // print using pointers
    printf("Matrix (using **):\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
            printf("%4d", *(*(arr+i)+j));

        printf("\n");
    }

    // print using index to TEST that the answer is correct and equivalent
    printf("Matrix (using [][]):\n");

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
            printf("%4d", arr[i][j]);

        printf("\n");
    }

    return 0;
}