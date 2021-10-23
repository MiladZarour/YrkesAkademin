#include <stdio.h>


// "YYMMDD-NNNC"


/*
____ get_str_length( __ )
{
    return ___
}
*/

void function1()
{
    char *str1 = "ABC";
    char *str2 = "123-456-789";
    int length1 = 0;
    int length2 = 0;

    // length1 = get_str_length(___)
    // length2 = get_str_length(___)

    printf("The length of %s is %d", str1, length1);
    printf("The length of %s is %d", str2, length2);

    // expected
    // The length of ABC is 3
}

/* make a function to conver strings to numbers
   tip: use this function strtol

   ____ get_long(_____)
   {
       ///
       return ____;
   }
*/

void function2()
{
    char *str_num1 = "10";
    char *str_num2 = "20";
    int n1 = 0;
    int n2 = 0;
    /*
    write your own code here to conver str_num1 & str_num2 to numbers
    use the "get_long" function here
    */

    /////
    int r = n1 + n2;
    printf("%d + %d = %d\n", n1, n2, r);
    // expecting
    // 10 + 20 = 30;
}

int main()
{
    function1();
    function2();
    printf("bye!\n");
    return 0;
}