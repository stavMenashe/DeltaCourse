/*------------------------------------------------------
* Filename: encryption.c
* Description: encrypt a given set of words.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NUM_OF_NUMS (26)
#define MAX_INPUT_LEN (256)
#define INC_VAL (5)
#define MOVE_VAL (4)
#define MUL_EVEN (7)
#define MOVE_VAL_BACK (5)

void int_to_char(char letter_arr[NUM_OF_NUMS], int nums_arr[NUM_OF_NUMS]);
void minus_five(int nums_arr[NUM_OF_NUMS]);
void move_four(int nums_arr[NUM_OF_NUMS], int move_step);
void even_dev_seven(int nums_arr[NUM_OF_NUMS]);
void inc_in_five(int nums_arr[NUM_OF_NUMS], int move_step);
void dec_prev(int nums_arr[NUM_OF_NUMS]);
void replace_half(int nums_arr[NUM_OF_NUMS]);

int main() {
    char letter_arr[NUM_OF_NUMS];
    int nums_arr[NUM_OF_NUMS];
    char user_input[MAX_INPUT_LEN];
    int index;

    printf("Insert a %d numbers (an array of %d integers): ", NUM_OF_NUMS, NUM_OF_NUMS);

    fgets(user_input, sizeof(user_input), stdin);
    index = 0;
    char *num = strtok(user_input, " ");

    /*Puting the given string inside an array.*/
    while (index < NUM_OF_NUMS){
        nums_arr[index] = atoi(num);
        ++index;
        num = strtok(NULL, " ");
    }

    
    replace_half(nums_arr);
    dec_prev(nums_arr);
    inc_in_five(nums_arr, MOVE_VAL_BACK);
    even_dev_seven(nums_arr);
    move_four(nums_arr, NUM_OF_NUMS - MOVE_VAL);
    minus_five(nums_arr);
    int_to_char(letter_arr, nums_arr);

    index = 0;
    while (index < NUM_OF_NUMS){
        printf("%c", letter_arr[index]);
        index += 1;
    }
    
    return 0;
}



/*------------------------------------------------------
* Function Name - int_to_char
* Function Purpose - Casts all the chars in an array to integers.
* Parameters –  letter_arr - The array of chars.
                nums_arr - The new array of integers.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void int_to_char(char letter_arr[NUM_OF_NUMS], int nums_arr[NUM_OF_NUMS]){
    int index = 0;
    while (index < NUM_OF_NUMS){
        letter_arr[index] = (char)nums_arr[index];
        ++index;
    }
    return;
}

/*------------------------------------------------------
* Function Name - minus_five
* Function Purpose - Decrease all the numbers in an array in INC_VAL.
* Parameters –  letter_arr - The array of chars.
                nums_arr - The new array of integers.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void minus_five(int nums_arr[NUM_OF_NUMS]){
    int index = 0;
    for (index = 0 ; index < NUM_OF_NUMS ; ++index){
        nums_arr[index] -= INC_VAL;
    }
    return;
}

/*------------------------------------------------------
* Function Name - move_four
* Function Purpose - Move each number move_step indeces forward.
* Parameters – nums_arr - The new array of integers.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void move_four(int nums_arr[NUM_OF_NUMS], int move_step){
    int temp_arr[NUM_OF_NUMS] = {0};
    int index = 0;

    while (index < NUM_OF_NUMS){
        temp_arr[index] = nums_arr[index];
        index += 1;
    }

    index = 0;
    while (index < NUM_OF_NUMS){
        if (index - move_step < 0){
            nums_arr[index] = temp_arr[index + NUM_OF_NUMS - move_step];
        }
        else{
            nums_arr[index] = temp_arr[index - move_step];
        }
        index += 1;
    }
    return;
}

/*------------------------------------------------------
* Function Name - even_dev_seven
* Function Purpose - Devides the values of the even indices by MUL_EVEN.
* Parameters – nums_arr - The array of integers.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void even_dev_seven(int nums_arr[NUM_OF_NUMS]){
    int index = 0;
    while(index < NUM_OF_NUMS){
        if (index % 2 == 0){
            nums_arr[index] = nums_arr[index] / MUL_EVEN;
        }
        index += 1;
    }
    return;
}

/*------------------------------------------------------
* Function Name - inc_in_five
* Function Purpose - Move each number move_step indeces forward.
* Parameters – nums_arr - The array of integers.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void inc_in_five(int nums_arr[NUM_OF_NUMS], int move_step){
    move_four(nums_arr, move_step);
    return;
}

/*------------------------------------------------------
* Function Name - dec_prev
* Function Purpose - Decrease the i-th value with the (i+1)th value.
* Parameters – nums_arr - The array of integers.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void dec_prev(int nums_arr[NUM_OF_NUMS]){
    int index = NUM_OF_NUMS;
    while (index > 0){
        nums_arr[index] -= nums_arr[index - 1];
        --index;
    }
    return;
}

/*------------------------------------------------------
* Function Name - replace_half
* Function Purpose - Replace the first half with the second half.
* Parameters – nums_arr - The array of integers.
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void replace_half(int nums_arr[NUM_OF_NUMS]){
    int half = NUM_OF_NUMS / 2;
    int first_half_arr[half];
    int second_half_arr[half];
    int index = 0, index1 = 0, index2 = 0;

    while (index < half){
        first_half_arr[index] = nums_arr[index];
        index += 1;
    }
    while (index < NUM_OF_NUMS){
        second_half_arr[index2] = nums_arr[index];
        index += 1;
        index2 += 1;
    }

    index = 0;
    index1 = 0;
    index2 = 0;
    while (index < NUM_OF_NUMS){
        if (index < half){
            nums_arr[index] = second_half_arr[index2];
            index2 += 1;
        }
        else{
            nums_arr[index] = first_half_arr[index1];
            index1 += 1;
        }
        index += 1;
    }

    return;
}