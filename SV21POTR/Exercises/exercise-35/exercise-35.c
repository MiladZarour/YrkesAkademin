#include <stdio.h>

/*
Beskrivning
Make a function to find the greatest common divisor (gcd) of two unsigned integers. E.g the gcd of 8 and 12 is 4.

Make a function to find the least common multiple (lcm) of two unsigned integers. E.g. the lcm of 4 and 6 is 12.
*/

unsigned gcd(unsigned a, unsigned b)
{
    unsigned gcd = 1;
    for (int i=1; i<=a && i<=b; i++)
        if(a%i==0 && b%i==0) // search for greatest from 1 to max(a,b)
            gcd = i;

    return gcd;
}

unsigned lcm(unsigned a, unsigned b)
{
    return (a*b) / gcd(a, b);
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("The GCD of %d and %d is %d\n", a, b, gcd(a,b));
    printf("The LCM of %d and %d is %d\n", a, b, lcm(a,b));

    return 0;
}