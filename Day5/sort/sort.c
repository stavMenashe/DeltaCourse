/*------------------------------------------------------
* Filename: sort.c
* Description: Gets 5 strings from the user and Sorts it.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_scanf.h"


#define NUM_OF_STR (5)
#define BIGGER (1)
#define EQUAL (0)
#define SMALLER (-1)
#define EMPTY_STRING ("")

#define ERROR_STR_LEN (-2)
#define ERROR_INVALID (-3)
#define ERROR_ARR (-4)

char* dyn_scanf(void);
void sort(void **arr, size_t arr_size, int (*compare)(const void*, const void*));
int compare_by_length(const void *a, const void *b);
int compare_by_alphabet(const void *a, const void *b);
void get_input(char *str_arr[NUM_OF_STR]);
int error_str_len();
int error_invalid_value();
int error_arr();

int main() {
    size_t i;

    char *str_arr[NUM_OF_STR];
    get_input(str_arr);

    sort((void**)str_arr, NUM_OF_STR, compare_by_length);
    for (i = 0; i < NUM_OF_STR - 1; ++i) {
        printf_s("%s, ", str_arr[i]);
    }
    printf_s("%s\n", str_arr[i]); /*Print the last val without a ','*/

    sort((void**)str_arr, NUM_OF_STR, compare_by_alphabet);
    for (i = 0; i < NUM_OF_STR - 1; ++i) {
        printf_s("%s, ", str_arr[i]);
    }
    printf_s("%s\n", str_arr[i]); /*Print the last val without a ','*/

    return 0;
}

/*------------------------------------------------------
* Function Name - sort
* Function Purpose - Sorts two strings by givven order.
* Parameters - arr - An array of the given strings.
                arr_size - The size of the arr.
                compare - the comparing function.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void sort(void **arr, size_t arr_size, int (*compare)(const void*, const void*)){
    size_t i, j;
    if (!arr || arr_size == 0 || !compare) {
        error_invalid_value();
        return;
    }

    char *temp;
    for (i = 0; i < arr_size - 1; ++i) {
        for (j = 0; j < arr_size - i - 1; ++j) {
            if (compare(&arr[j], &arr[j + 1]) == BIGGER) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*------------------------------------------------------
* Function Name - compare_by_length
* Function Purpose - Compers two pointers to strings by length.
* Parameters –str_arr - An array of the given strings.
* Return Values - the result.
* Author - Stav Menashe
-------------------------------------------------------*/
int compare_by_length(const void *a, const void *b){
    const char *str_a = *(const char**)a;
    const char *str_b = *(const char**)b;

    if (!str_a || !str_b) {
        return error_invalid_value();
    }

    size_t len_a = strlen(str_a);
    size_t len_b = strlen(str_b);

    if (len_a == INT_MAX || len_b == INT_MAX) {
        return error_str_len();
    }

    if (len_a > len_b){
        return BIGGER;
    }
    else if (len_a < len_b){
        return SMALLER;
    }
    return EQUAL;
}

/*------------------------------------------------------
* Function Name - compare_by_alphabet
* Function Purpose - Compers two pointers to strings by alphabet order.
* Parameters –str_arr - An array of the given strings.
* Return Values - the result.
* Author - Stav Menashe
-------------------------------------------------------*/
int compare_by_alphabet(const void *a, const void *b){
    const char *str_a = *(const char**)a;
    const char *str_b = *(const char**)b;

    if (!str_a || !str_b) {
        return error_invalid_value();
    }

    int res = strcmp(str_a, str_b);
    
    if (res > 0){
        return BIGGER;
    }
    if (res < 0){
        return SMALLER;
    }
    return EQUAL;
}

/*------------------------------------------------------
* Function Name - get_input
* Function Purpose - get 5 strings as input.
* Parameters –str_arr - An array of the given strings.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void get_input(char *str_arr[NUM_OF_STR]){
    size_t i;

    for (i = 0 ; i < NUM_OF_STR ; ++i){
        printf_s("\nWrite the %d sting: ", i + 1);
        str_arr[i] = dyn_scanf();
        if (str_arr[i] == NULL){
            error_arr();
            return;
        }
    }
}

/*------------------------------------------------------
* Function Name - error_str_len
* Function Purpose - Prints an error msg for string too big.
* Parameters –
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
int error_str_len(){
    printf_s("Error: there is a string that is too big.\n");
    return ERROR_STR_LEN;
}

/*------------------------------------------------------
* Function Name - error_invalid_value
* Function Purpose - Prints an error msg for invalid value.
* Parameters –
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
int error_invalid_value(){
    printf_s("Error: invalid value (array/array length/compare function/string length).\n");
    return ERROR_INVALID;
}

/*------------------------------------------------------
* Function Name - error_arr
* Function Purpose - Prints an error msg for assigning string to the array.
* Parameters –
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
int error_arr(){
    printf_s("Error: Could'nt assign string to the array.\n");
    return ERROR_ARR;
}