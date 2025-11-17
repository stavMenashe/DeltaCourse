/*------------------------------------------------------
* Filename: print_hanukia.c
* Description: prints hanukia with n candles when n is givven as an input.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>

#define ROW_LEN (45)

int main() {
    int candle_num = 0;
    printf("How many candles there are today? (Integer between 1 to 8): ");
    scanf("%d", &candle_num);

    char * candle_arr[ROW_LEN] = {" #                                           \n",
                         " #     #                                     \n",
                         " #     #     #                               \n",
                         " #     #     #     #                         \n",
                         " #     #     #     #     #                   \n",
                         " #     #     #     #     #     #             \n",
                         " #     #     #     #     #     #     #       \n",
                         " #     #     #     #     #     #     #     # \n"};

    printf("        %s\
        ###   ###   ###   ###   ###   ###   ###   ###\n\
        ###   ###   ###   ###   ###   ###   ###   ###\n\
        ###   ###   ###   ###   ###   ###   ###   ###\n\
        ###   ###   ###   ###   ###   ###   ###   ###\n\
        #############################################\n\
                             | |                     \n\
                             | |                     \n\
                             | |                     \n\
                             | |                     \n\
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^", candle_arr[candle_num - 1]);

    return 0;
}