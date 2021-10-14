#include <stdio.h>
#include <string.h>

/*
Beskrivning
Make a program to get a string from the standard input,
then print the string to the output in reverse order.

For examaple:
Enter a string: ABCDEF
Reversed string: FEDCBA
*/

#define ARR_SIZE 255

void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    char str[ARR_SIZE];

    // get the text
    printf("Enter a text:\n");
    gets(str); // use gets just for the sake of simplicity. The focus is on reversing!

    // reverse the text
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
        swap(str+i, str+len-i-1);

    // print result
    printf("Reversed:\n%s\n", str);
    return 0;
}