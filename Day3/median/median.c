/*------------------------------------------------------
* Filename: median.c
* Description: sequentially accepts an unknown number of integers, until
               it receives an input that is not a number, and
               find the median of all these numbers and print it.
* Author: Stav Menashe.

!!!!!!currently I only did part A, in the future I will add part B!!!!!
-------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>

void get_input(int **nums_arr, int *len);

int main() {
    int *nums_arr = NULL;
    int len = 0;

    get_input(&nums_arr, &len);

    free(nums_arr);
    return 0;
}

void get_input(int **nums_arr, int *len) {
    int curr_num;
    int check;

    printf("Write the sequence of numbers: ");

    while (1) {
        check = scanf("%d", &curr_num);

        if (check != 1) {
            break;
        }

        *nums_arr = realloc(*nums_arr, (*len + 1) * sizeof(int));
        (*nums_arr)[*len] = curr_num;
        (*len)++;
    }
}
