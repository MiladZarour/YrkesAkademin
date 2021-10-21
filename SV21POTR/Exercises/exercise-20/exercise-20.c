#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Beskrivning
Make a program to get a string as an argument from the command line,
then convert the uppercase letters to lowercase and vice versa and in
the end print the string to the standard output.

To change and print the string use only pointers.
*/

char *toggle(char *str)
{
    for (char *p = str; p && *p; p++)
    {
        printf("The value insisde the pointer str: %p and dereferncing *str is: %c\n", str, *str); //for debugging
        printf("The value inside pointer p is: %p, and derefernceing *p is: %c\n", p, *p);         //for debugging
        printf("p && *p = %d\n", p && *p);                                                         //for debugging

        if (isalpha(*p))
        {
            *p = isupper(*p) ? tolower(*p) : toupper(*p);
            printf("Now The value insisde the pointer str: %p and dereferncing *str is: %c\n", str, *str); //for debugging
            printf("Now The value inside pointer p is: %p, and derefernceing *p is: %c\n\n", p, *p);       //for debugging
        }
    }
    return str;
}

int main(int argc, char *argv[])
{
    printf("Argument count: %d\n\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("Argument value[%d]: %s\n", i, argv[i]);
        printf("Argument toggled:  %s\n\n", toggle(argv[i]));
    }

    return 0;
}

/*         printf("Argument toggled:  %s\n\n", toggle(argv[0]));  text1
     
      "  t  e  x  t  1  \0"
        

char* toggle(char *str)
{
    for(char *p=str; p && *p; p++)
        if(isalpha(*p))
            *p = isupper(*p) ? tolower(*p) : toupper(*p);

    return str;
}
 */