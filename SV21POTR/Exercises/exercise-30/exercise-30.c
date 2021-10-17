#include <stdio.h>

/*
Beskrivning
1) Create two pointers pa and pb to int a = 5; char b = ’s’;
2) Change values of a and b VIA the pointers
3) Create a function that takes a variabel (pa above) as a parameter and add 5 to it.
4) Create a function pointer, funcptr, to the following function and execute it.
*/


// 3) Create a function that takes a variabel (pa above) as a parameter and add 5 to it.
void my_function(int *p)
{
    *p += 5;
}

int main()
{
// 1) Create two pointers pa and pb to int a = 5; char b = ’s’;
    int a = 5;
    char b = 's';

    int *pa = &a;
    char *pb = &b;
    printf("Original values: a=%i b='%c'\n", a, b);

// 2) Change values of a and b VIA the pointers
    *pa = 50;
    *pb = 'X';
    printf("After using pointer.. a=%i b='%c'\n", a, b);

// 3) Create a function that takes a variabel (pa above) as a parameter and add 5 to it.
    my_function(pa);
    printf("After my_function.. a=%i\n", a);

// 4) Create a function pointer, funcptr, to the following function and execute it.
    void (*ptr_function)(int*) = my_function; // declare & initialize
    ptr_function(pa); // execute
    printf("After ptr_function.. a=%i\n", a);

    return 0;
}
