/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: print the values and the addresses of an array. 
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARR_SIZE (8)
#define INPUT_SIZE (16) /*ARR_SIZE * 2 because of the spaces*/

void get_num_arr_input(int numbers[ARR_SIZE]);
void get_char_arr_input(char chars[ARR_SIZE]);

int main() {
    int numbers[ARR_SIZE];
    char chars[ARR_SIZE];
        int index;

    get_num_arr_input(numbers);
    get_char_arr_input(chars);

    printf("The values and addresses of the numbers array.\n");
    for (index = 0 ; index < ARR_SIZE ; ++index){
        printf("%d: %p\n", numbers[index], &(numbers[index]));
    }
    printf("-----------------------------------------------\n");

    printf("The values and addresses of the char's array.\n");
    for (index = 0 ; index < ARR_SIZE ; ++index){
        printf("%c: %p\n", *(chars + index), chars + index);
    }
    return 0;
}

/*------------------------------------------------------
* Function Name - get_num_arr_input.
*
* Function Purpose - get integers and create an array from them.
*
* Parameters –  numbers - the given integers will be inserted into this array.
*
* Return Values -
*
* Author - Stav Menashe.
-------------------------------------------------------*/
void get_num_arr_input(int numbers[ARR_SIZE]){
    char input[INPUT_SIZE];
    int index;
    printf("Enter %d integers: ", ARR_SIZE);
    for (index = 0; index < ARR_SIZE; ++index) {
        scanf("%d", &numbers[index]);
    }
    return;
}

/*------------------------------------------------------
* Function Name - get_char_arr_input
*
* Function Purpose - get chars and create an array from them.
*
* Parameters –  chars - the given chars will be inserted into this array.
*
* Return Values -
*
* Author - Stav Menashe.
-------------------------------------------------------*/
void get_char_arr_input(char chars[ARR_SIZE]){
    char input[INPUT_SIZE];
    int index;
    printf("Enter %d char's: ", ARR_SIZE);
    for (index = 0; index < ARR_SIZE; ++index) {
        scanf(" %c", &chars[index]); 
    }
    return;
}