/*------------------------------------------------------
* Filename: const_pointer.c
* Description: replace the chanel on tv.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>

#define START_CHANNEL (1)

int main() {
    const int starting_channel = START_CHANNEL;
    const int *channel = &starting_channel;

    printf("The current channel is: %d\n", *channel);

    printf("What is the new chanel? ");
    scanf("%d", channel);

    printf("The new channel is : %d\n", *channel);

    return 0;
}