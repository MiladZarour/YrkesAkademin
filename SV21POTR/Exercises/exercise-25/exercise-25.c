#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Beskrivning
Make a function to fill an array of type int with unique random numbers.
Make another function to print an array of type int to the output.
Example: An array filled with random numbers: {9, 3, 8, 0, 5, 2, 6, 7, 1, 4}
*/

#define ARR_SIZE 15

int find_arr(int *arr, unsigned size, int x)
{
    for (int i = 0; i < size; i++)
        if(x == arr[i])
            return i;

    return -1;
}

void rand_unique_arr(int *arr, unsigned size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
        do {
            arr[i] = rand() % 1000;
        } while (i>0 && find_arr(arr, i-1, arr[i]) >= 0);
}

void print_arr(const int *arr, unsigned size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("}\n");
}

int main()
{
    int arr[ARR_SIZE];

    // randomize and print
    rand_unique_arr(arr, ARR_SIZE);
    printf("Array with unique values:\n");
    print_arr(arr, ARR_SIZE);

    return 0;
}