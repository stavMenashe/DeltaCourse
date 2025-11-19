/*------------------------------------------------------
* Filename: median.c
* Description: sequentially accepts an unknown number of integers, until
               it receives an input that is not a number, and
               find the median of all these numbers and print it.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void get_input(int **nums_arr, int *len);
void sort_arr(int *num_arr, int len);
void swap(int *a, int *b);
int return_median(int *num_arr, int len);

int main() {
    int *nums_arr = NULL;
    int len = 0;
    int median;

    get_input(&nums_arr, &len);
    median = return_median(nums_arr, len);
    
    printf("The median of the givven array is : %d", median);

    free(nums_arr);
    return 0;
}

/*------------------------------------------------------
* Function Name - get_input
* Function Purpose - Get an input of numbers and create an array from it.
* Parameters –  nums_arr - the array of numbers
*		        len - the length of the givven array.
* Return Values -
* Author - Stav Menahse.
-------------------------------------------------------*/
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

/*------------------------------------------------------
* Function Name - sort_arr
* Function Purpose - Sort the givven array.
* Parameters –  nums_arr - the array of numbers
*		        len - the length of the givven array.
* Return Values -
* Author - Stav Menahse.
-------------------------------------------------------*/
void sort_arr(int *num_arr, int len){
    int i, j;
    for (i = 0 ; i < len ; ++i){
        for (j = 0 ; j < len ; ++j){
            if (*(num_arr + i) < *(num_arr + j)){
                swap((num_arr + i), (num_arr + j));
            }
        }
    }
    return;
}

/*------------------------------------------------------
* Function Name - swap
* Function Purpose - Swap the values of two pointers.
* Parameters –  a - The first pointer.
*		        b - The second pointer.
* Return Values -
* Author - Stav Menahse.
-------------------------------------------------------*/
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*------------------------------------------------------
* Function Name - return_median
* Function Purpose - Return the median of a givven array.
* Parameters –  nums_arr - the array of numbers
*		        len - the length of the givven array.
* Return Values - The median of the givven array.
* Author - Stav Menahse.
-------------------------------------------------------*/
int return_median(int *num_arr, int len){
    sort_arr(num_arr, len);
    int med_len = len / 2;
    return *(num_arr + med_len);
}