#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

/*
Beskrivning
Make a program to read date and time in the format of YYYY-MM-DD HH:mm:ss from the input
and check if the entered date and time is in the correct format or not.
*/

#define SHOW_LOG 1

typedef struct DATETIME
{
    unsigned int year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
} datetime_t;

// Levels for the parser
typedef enum LEVEL
{
    L_YYYY = 0,
    L_MM,
    L_DD,
    L_HH,
    L_mm,
    L_ss,
    L_OK,
} level_t;

const char *LVL_NAME[] = {
    "year",
    "month",
    "day",
    "hour",
    "minutes",
    "seconds",
    "ok",
};

bool verify_digits_n(level_t level, unsigned digits, unsigned amount)
{
    printf(">>>>>>Now we are inside bool verify_digits_n:\n");
    printf("level = %d, digits = %d, amount = %d\n", level, digits, amount);
    // here we dceide if we want EXACT amount of digits or between [1 - amount]
    if (digits >= 1 && digits <= amount)
    {
        printf("digits which is %d >= 1 &&  digits which is %d <= amount which is %d\n\n", digits, digits, amount);
        //if(digits==amount)
        return true;
    }
#if SHOW_LOG
    printf("..level %d error -> %s: expected %d digits (inserted %d digits)\n", level, LVL_NAME[level], amount, digits);
#endif

    return false;
}

// Simple digits verification
bool verify_digits(level_t level, unsigned digits)
{
    printf(">>>Now we are inside bool verify_digits\n");
    printf("Level is: %d , digits is : %d\n", level, digits);
    switch (level)
    {
    case L_YYYY:
    {
        printf("Checking the case L_YYYY = %d\n", L_YYYY);
        return verify_digits_n(level, digits, 4);
    }

    case L_MM:
    case L_DD:
    case L_HH:
    case L_mm:
    case L_ss:
    {
        printf("Checking the case L_MM = %d L_DD = %d L_HH = %d L_mm = %d L_ss = %d\n", L_YYYY, L_DD, L_HH, L_mm, L_ss);
        return verify_digits_n(level, digits, 2);
    }

    case L_OK:
        return true;
    }

    return false;
}

bool verify_range_n(level_t level, unsigned number, unsigned n1, unsigned n2)
{
    printf(">>>>>>Now we are inside bool verify_range_n:\n");
    printf("level = %d, digits = %d, n1 = %lu, n2 = %d\n", level, number, n1, n2);
    if (number >= n1 && number <= n2)
    {
        printf("number which is %d >= n1 which is %d && number which is %d <= n2 which is %d\n\n", number, n1, number, n2);
        return true;
    }

#if SHOW_LOG
    printf("..level %d error -> %s: expected range %d-%d for number %d\n", level, LVL_NAME[level], n1, n2, number);
#endif

    return false;
}

// Calculate the amount of days in a month
int get_month_days(unsigned short year, unsigned char month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return 29;
        return 28;
    }

    assert(0);
    return 0;
}

// Simple range verification
bool verify_range(level_t level, unsigned number, const datetime_t *dt)
{
    printf(">>>Now we are inside bool verify_range:\n");
    printf("level = %d, number = %d, *dt = %d, dt = %p\n", level, number, *dt, dt);
    switch (level)
    {
    case L_YYYY:
    {
        printf("Checking the case L_YYYY = %d\n", L_YYYY);
        return verify_range_n(level, number, 0, 9999);
    }

    case L_MM: // 1-12
    {
        printf("Checking the case L_MM = %d\n", L_MM);
        return verify_range_n(level, number, 1, 12);
    }

    case L_DD: // 1-31 (or 30,29,28)
    {
        printf("Checking the case L_DD = %d\n", L_DD);
        return verify_range_n(level, number, 1, get_month_days(dt->year, dt->month));
    }

    case L_HH: // 0-23
    {
        printf("Checking the case L_HH = %d\n", L_HH);
        return verify_range_n(level, number, 0, 23);
    }

    case L_mm: // 0-59
    case L_ss:
    {
        printf("Checking the case L_mm = %d , L_ss = %d\n", L_mm, L_ss);
        return verify_range_n(level, number, 0, 59);
    }

    case L_OK:
        return true;
    }

    return false;
}

bool verify_delimiter_n(level_t level, char c, char *valid, unsigned number)
{
    printf(">>>>>>Now we are inside bool verify_delimiter_n:\n");
    printf("level = %d, c = %c, *valid = %c, valid = %p , number = %d\n", level, c, *valid, valid, number);
    if (strchr(valid, c))
    {
        printf("strchr(valid, c) = %p , and *strchr(valid, c) = %c\n\n", strchr(valid, c), *strchr(valid, c));
        return true;
    }

#if SHOW_LOG
    // quick fix the '\n' delimiter into something visible
    // TODO: make it better!
    char txt[20] = {0};
    if (strchr(valid, '\n'))
        strcpy(txt, "\\n (enter)");
    else
        txt[0] = valid[0];

    //printf("..level %d error -> %s: expected delimiter '%c' after number %d\n", level, LVL_NAME[level], valid, number);
    printf("..error: expected %s delimiter '%s' after number %d\n", LVL_NAME[level], txt, number);
#endif

    return false;
}

// Simple verification
// issue: it is ok to use '/' or '.' as delimiter in between of year-month-day ?
bool verify_delim(level_t level, char delim, unsigned number)
{
    printf(">>>Now we are inside bool verify_delim:\n");
    printf("level = %d, delim = %c , number = %d\n", level, delim, number);
    switch (level)
    {
    case L_YYYY:
    case L_MM:
    {
        printf("Checking the case L_YYYY = %d , or L_MM = %d\n", L_YYYY, L_MM);
        return verify_delimiter_n(level, delim, "-", number);
    }

    case L_DD:
    {
        printf("Checking the case L_DD = %d\n", L_DD);
        return verify_delimiter_n(level, delim, " ", number);
    }

    case L_HH:
    case L_mm:
    {
        printf("Checking the case L_HH = %d , or L_mm = %d\n", L_HH, L_mm);
        return verify_delimiter_n(level, delim, ":", number);
    }

    case L_ss:
    {
        printf("Checking the case L_ss = %d\n", L_ss);
        return verify_delimiter_n(level, delim, "\n ", number);
    }

    case L_OK:
        return true;
    }

    return false;
}

bool set_datetime_value(level_t level, datetime_t *dt, unsigned number)
{
    printf("Now we are inside bool set_datetime_value:\n");
    printf("level = %d, *dt = %c , dt = %p , number = %d\n\n", level, *dt, dt, number);

    assert(verify_range(level, number, dt));

    switch (level)
    {
    case L_YYYY:
    {
        printf("dt->year = %d\n", dt->year);
        dt->year = number;
        printf("dt->year = %d\n\n\n", dt->year);
        // printf("*(dt->year) = %p\n", *(dt->year));
        return true;
    }

    case L_MM:
    {
        printf("dt->month = %d\n", dt->month);
        dt->month = number;
        printf("dt->month = %d\n", dt->month);
        return true;
    }

    case L_DD:
    {
        printf("dt->day = %d\n", dt->day);
        dt->day = number;
        printf("dt->day = %d\n", dt->day);
        return true;
    }

    case L_HH:
    {
        printf("dt->hour = %d\n", dt->hour);
        dt->hour = number;
        printf("dt->hour = %d\n", dt->hour);
        return true;
    }

    case L_mm:
    {
        printf("dt->min = %d\n", dt->min);
        dt->min = number;
        return true;
        printf("dt->min = %d\n", dt->min);
    }

    case L_ss:
    {
        printf("dt->sec = %d\n", dt->sec);
        dt->sec = number;
        return true;
        printf("dt->sec = %d\n", dt->sec);
    }

    case L_OK:
        return true;
    }

    return false;
}

// Simple verification
// issue: is it OK to have date only (without time) ?
// issue: is it OK to have time only (without date) ?
// issue: is it OK to have time without seconds ?
// --> for the sake of simplicity we validate TRUE only with a complete FULL FORMAT

int main()
{
    unsigned c, number = 0, digits = 0;
    level_t level = L_YYYY;
    datetime_t dt = {0};

    printf("Enter date and time [YYYY-MM-DD HH:mm:ss]:\n");

    // stay in the loop until is finished, or internal error/break
    while (level != L_OK)
    {
        printf("------------------------------------------\n");
        c = getchar();
        printf("You enter the character: %c\n", c);
        // if is digit
        if (isdigit(c))
        {
            // build the number
            digits++;
            printf("digits variable is :  %d\n", digits);
            number = number * 10 + c - '0';
            printf("number variable is :  %d\n", number);
        }
        // if valid number (verify everything)
        else if (verify_digits(level, digits) &&     // verify: amount of digits
                 verify_range(level, number, &dt) && // verify: range of the number
                 verify_delim(level, c, number))     // verify: delimiter is the correct for the level
        {
#if SHOW_LOG
            // show internal information after verification: OK bla bla..
            printf("..level %d OK (%s: %d)\n\n\n", level, LVL_NAME[level], number);
#endif

            // update the result DT structure
            printf(".....|||||update the result DT structure|||||......\n");
            set_datetime_value(level, &dt, number);

            // prepare to build a new number
            number = 0;
            digits = 0;
            // ..and increment to next level
            level++;
        }
        // if not valid
        else
        {
            // error ..bye bye!
            break;
        }
    }

    if (level == L_OK)
    {
        printf("The format is valid!\n");
        printf("Result after parsing: %4u-%02u-%02u %02d:%02d:%02d\n",
               dt.year, dt.month, dt.day, dt.hour, dt.min, dt.sec);
    }
    else
        printf("Format not valid\n");

    return 0;
}