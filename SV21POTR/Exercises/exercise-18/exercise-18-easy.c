#include <stdio.h>

/*
Beskrivning
Make a program to read date and time in the format of YYYY-MM-DD HH:mm:ss from the input
and check if the entered date and time is in the correct format or not.
*/


int main()
{
    int y, m, d, h, mi, s, res;

    printf("Enter date and time [YYYY-MM-DD HH:mm:ss]:\n");
    res = scanf("%4d-%2d-%2d %2d:%2d:%2d", &y, &m, &d, &h, &mi, &s);

    // should we validate the values of each variable ?
    // ..or shall we focus only in the format ?

    if (res == 6)
        printf("The format is valid\n");
    else
        printf("Format not valid\n");

    return 0;
}