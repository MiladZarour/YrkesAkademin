




#include <stdio.h>

typedef struct 
{
    int y, m, d;
} ymd_t;

int get_YMD_v1(int *y, int *m, int *d)
{
    // if calculation is correct
    if(1)
    {
        *y = 1990;
        *m = 10;
        *d = 28;
        return 1;
    }
    return 0;
}

int get_YMD_v2(ymd_t *ymd)
{
    // if calculation is correct
    if(1)
    {
        ymd->y = 1990;
        ymd->m = 10;
        ymd->d = 28;
        return 1;
    }
    return 0;
}

ymd_t get_YMD_v3()
{
    ymd_t ymd;
    // if calculation is correct
    ymd.y = 1990;
    ymd.m = 10;
    ymd.d = 28;
    return ymd;
}

int main()
{
    // equivalent to the next comment
    int d, m, y;

    if(get_YMD_v1(&y, &m, &d))
    {
        // print values
    }
    else
    {
        // print error
    }

    // 

    ymd_t ymd;
    if(get_YMD_v2(&ymd))
    {
        // print values
    }
    else
    {
        // print error
    }

    ymd_t ymd3 = get_YMD_v3();
    if( ymd3.y )
    {
        // print values
    }
    else
    {
        // print error
    }

    return 0;
}
