/*------------------------------------------------------
* Filename: num_sum.c
* Description: accepts a series of integers and checks whether the sum of the 
*              first and last number in the series is equal to the sum of all the other numbers.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>

#define ARR_LEN (100)

int main() {
    int index = 0;
    int num = 0;
    int sum_first_and_last = 0;
    int sum_middle = 0;

    printf("Enter a list of numbers: ");

    while (scanf("%d", &num) == 1 || num == '\0') {
        if (index == 0){
            sum_first_and_last += num;
        }
        else{
            sum_middle += num;
        }
        index += 1;
    }
    sum_first_and_last += num;

    if (sum_first_and_last == sum_middle){
        printf("")
    }
    return sum_first_and_last == sum_middle;
}