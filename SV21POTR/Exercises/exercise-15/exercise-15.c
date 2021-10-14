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
#define USE_SWAP 0

#if USE_SWAP
void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}
#endif

int main()
{
    char str[ARR_SIZE];

    // get the text
    printf("Enter a text:\n");
    gets(str); // use gets just for the sake of simplicity. The focus is on reversing!

    // reverse the text
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        #if USE_SWAP
        swap(str + i, str + len - i - 1);
        #else
        char c = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = c;
        #endif

        printf("..swap [%d]='%c' with [%d]='%c' -> %s\n", i, str[i], len - i - 1, str[len - i - 1], str);
    }

    // print result
    printf("Reversed:\n%s\n", str);
    return 0;
}