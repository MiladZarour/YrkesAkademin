#include <stdio.h>

/*
Beskrivning
Make a function to count the digits of a given number using recursion. E.g. 456 has 3 digits
Make a function to calculate X power Y; i.e (XY ) using recursion. E.g. 2^3 = 8. X and Y are two integers.
Using unity test the functions.
*/


unsigned digits(int x)
{
    return x<10 ? 1 : 1 + digits(x/10);
}

unsigned power(int x, int pow)
{
    return x * (pow>1 ? power(x, pow-1) : 1);
}

int main()
{
    int x=0, y=0;

    printf("Enter a number: ");
    scanf("%d", &x);
    printf("The number %d has %u digits\n", x, digits(x));

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("The result of %d^%d is %u\n", x, y, power(x, y));

    return 0;
}