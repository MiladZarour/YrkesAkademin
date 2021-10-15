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

char* toggle(char *str)
{
    char *p = str;

    while(p && *p)
    {
        if(isalpha(*p))
        {
            if(isupper(*p))
                *p = tolower(*p);
            else
                *p = toupper(*p);
        }

        p++;
    }

    return str;
}

int main(int argc, char *argv[])
{
    printf("Argument count: %d\n", argc);
    for(int i=0; i<argc; i++)
    {
        printf("Argument value[%d]: %s\n", i, argv[i]);
        printf("Argument toggled: %s\n\n", toggle(argv[i]));
    }

    return 0;
}