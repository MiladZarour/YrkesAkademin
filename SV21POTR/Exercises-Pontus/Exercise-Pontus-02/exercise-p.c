#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

static uint32_t EXER_REGISTER_SENDER;
static uint32_t EXER_REGISTER_RECEIVER;
static uint32_t EXER_BUFFER;

// start and end could easily swap places depending on the interpretation.. L->R or R->L
#define MSG_START 25
#define MSG_END 10

/*
4 checksum bits, 2 zero bits, 16 bits for message, 2 zero bits, 8 bits for flags

[0000][00][0000 0000 0000 0000][00][0000 0000]

Calculate checksum by adding all bits in the message togheter
Zero bits are just zero's
8bits for flag is for control

pos 0 = On / Off
pos 1 = Sending or reciving
pos 2 = Keep message after sending
pos 3 = Use checksum or not
pos 4 = Not used
pos 5 = Not used
pos 6 = Not used
pos 7 = Not used

Store the message in one register calculate the checksum, sending it to a buffer. 
Then get the message from the buffer using the other register, verifying and printing it out.

Remember to send along the checksum, if you need to.
Delete the message in the sender, if need to.

Try and make it so, setting flags is easy
*/

typedef enum
{
    F_ONOFF = 0x0001,
    F_SENDING = 0x0002,
    F_KEEP_MSG = 0x0004,
    F_USE_CHECKSUM = 0x0008,
} flag_t;

uint8_t get_checksum(uint32_t x)
{
    // checksum in message placed between bits 10-25
    uint8_t chksum = 0;
    for(int i=MSG_START; i>=MSG_END; i--)
        chksum += (x>>i)&1 ? 1 : 0;

    return chksum;
}

uint16_t get_message(uint32_t reg)
{
    reg &= 0x03FFFFFF; // kill 6 bits on the left
    reg >>= 10; // move the message to the right end
    return reg;
}

bool get_flag(uint32_t reg, flag_t flag)
{
    return (reg&flag) != 0;
}

void print_register(uint32_t reg)
{
    uint32_t bits = sizeof(reg)*8;

    printf("[chks][00][ - m e s s a g e - ][00][f l a g s]\n");
    printf("[");

    for(int i=bits-1; i>=0; i--)
    {
        if (i==7 || i==9 || i==25 || i==27)
            printf("][");
        else if (i==3 || i==13 || i==17 || i==21)
            printf(" ");

        printf("%c", (reg>>i)&1 ? '1' : '0');
    }

    printf("] <- %08X\n", reg);
}

void print_values(uint32_t reg)
{
    uint8_t chk = get_checksum(reg);
    uint16_t msg = get_message(reg);
    bool onoff = get_flag(msg, F_ONOFF);
    bool send = get_flag(msg, F_SENDING);
    bool keep = get_flag(msg, F_KEEP_MSG);
    bool usechk = get_flag(msg, F_USE_CHECKSUM);

    printf("[%4u]    [  %6u = 0x%04X  ]    [flags: USECHK=%d KEEP=%d SND=%d ONOFF=%d]\n", chk, msg, msg, usechk, keep, send, onoff);
}



bool send(uint32_t *sender, uint32_t *buffer)
{
    bool status = false;
    //use *sender to access the variable
    return status;
}

bool get(uint32_t *receiver, uint32_t *buffer)
{
    bool status = false;
    //use *receiver to access the variable
    return status;
}

void print_test(uint32_t reg, const char *txt)
{
    printf("Test: %s\n", txt);
    print_register(reg);
    print_values(reg);
    printf("\n");
}

int main(void)
{
    print_test(0xFC0003FF, "Calculate cheksum for EMPTY message"); 
    print_test(0x03FFFC00, "Calculate cheksum for FULL message"); 
    print_test(0x02AAA800, "Try zig-zag values for message"); 



    if (send(&EXER_REGISTER_SENDER, &EXER_BUFFER))
    {
        if (get(&EXER_REGISTER_RECEIVER, &EXER_BUFFER))
        {
            //print relevant things
        }
    }

    return 0;
}