
void memo()
{
    char a = 65;
    char b = 66;
    short int si = 100;
    //...
    char *pc = &a;
    *pc = 67;
    b++;
    pc++;
    *pc = 68;
    char **ppc = &pc;
    //*ppc = 
    //**ppc = 

    char arr[3] = {10,100,1000};

    /*
    pc = arr;
    //----- equivalent
    *pc = 33;
    *(pc + 0) = 33;
    pc[0] = 33;
    arr[0] = 33;
    //----- equivalent
    pc++; *pc = 44;
    *(pc + 1) = 44;
    arr[1] = 44;
    //----- equivalent
    pc+=offset; *pc = 44;
    *(pc + offset) = 44;
    arr[offset] = 44;
    */

    //----- equivalent
    for (char i = 0; i < 3; i++)
        arr[i] += 10;

    short xxx; // not initialized

    /*
    void *pv = &a;
    *(char*)pv = 1;  // sizeof 1 -> 0x 01
    *(short*)pv = 1; // sizeof 2 -> 0x 00 01 
    *(long*)pv = 1;  // sizeof 4 -> 0x 00 00 00 01
    */

    // equivalent loops
    char *pp = 0;
    for (pp = &arr; pp < &arr[3]; pp++)
        *pp += 10;

    for (int i = 0; i < 3; i++)
        arr[i] += 10;

    // crash the computer loop
    pp = &a;
    for (int i = 0; i < 200; i++)
        pp[i] += 10;
}