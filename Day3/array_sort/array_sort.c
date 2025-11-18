/*------------------------------------------------------
* Filename: array_sort.c
* Description: Sort an array of addresses.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (10)
#define INPUT_SIZE (20) /*ARRAY_LENGTH * 2 because of spaces.*/

void sort_addr(int *p_arr[ARRAY_LENGTH]);
void swap(int *p_arr[ARRAY_LENGTH], int i, int j);

int main() {
    int num_arr[ARRAY_LENGTH] = {0};
    int *p_arr[ARRAY_LENGTH];
    int index = 0;
    while (index < ARRAY_LENGTH){
        p_arr[index] = &num_arr[index];
        ++index;
    }

    char input[INPUT_SIZE];
    printf("Enter %d char's: ", ARRAY_LENGTH);
    for (index = 0; index < ARRAY_LENGTH; ++index) {
        if (scanf(" %d", &num_arr[index]) != 1){
            printf("An error accured");
            return 0;
        }
    }

    printf("The values and addresses of the array before the sorting.\n");
    for (index = 0 ; index < ARRAY_LENGTH ; ++index){
        printf("%d : %p\n", num_arr[index], p_arr[index]);
    }

    sort_addr(p_arr);

    printf("-----------------------------------------------\n");
    printf("The values and addresses of the array after the sorting.\n");
    for (index = 0 ; index < ARRAY_LENGTH ; ++index){
        printf("%d : %p\n", num_arr[index], p_arr[index]);
    }

    return 0;
}


/*------------------------------------------------------
* Function Name - sort_addr
*
* Function Purpose - Sort a the given array by the addresses.
*
* Parameters –  num_arr - The array with the values.
                p_arr - The array of pointers.
*
* Return Values -
*
* Author - Stav Menashe.
-------------------------------------------------------*/
void sort_addr(int *p_arr[ARRAY_LENGTH]){
    int i, j;
    for (i = 0 ; i < ARRAY_LENGTH ; ++i){
        for (j = 0 ; j < ARRAY_LENGTH ; ++j){
            if (*p_arr[j] > *p_arr[i]){
                swap(p_arr, i, j);
            }
        }
    }
    return;
}

/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - Swap the values of two numbers.
*
* Parameters –  p_arr - The array of pointers.
                i - The first index.
                j - The second index.
*
* Return Values -
*
* Author - Stav Menashe.
-------------------------------------------------------*/
void swap(int *p_arr[ARRAY_LENGTH], int i, int j){
    int *temp = p_arr[i]; 
    p_arr[i] = p_arr[j];      
    p_arr[j] = temp;  
    return;
}