/*------------------------------------------------------
* Filename: print_chars.c
* Description: prints a square of chars depends on the user input.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>

#define CHECK_EVEN (2)
#define THREE_DEVIDE (3)
#define FIVE_DEVIDE (5)

char check_char_type(int num);
int main() {
    int row, col;
    int user_num = -1 ; /*-1 for error handling.*/
    int check_input;
    char ch;

    printf("Enter a number: ");
    check_input = scanf("%d", &user_num);
    if (check_input < 1 || user_num < 0){
        printf("Bad Input!");
        return 0;
    }

    ch = check_char_type(user_num);

    for (row = 0 ; row < user_num ; ++row){
        for (col = 0 ; col < user_num ; ++col){
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}


/*------------------------------------------------------
* Function Name - check_char_type
* Function Purpose - return a char depends on the input and a given rules.
* Parameters –  num - The unput number.
* Return Values - The char.
* Author - Stav Menashe.
-------------------------------------------------------*/
char check_char_type(int num){
    if (num % CHECK_EVEN == 0){
        return '*';
    }
    else if (num % THREE_DEVIDE == 0){
        return '^';
    }
    else if (num % FIVE_DEVIDE == 0){
        return '%';
    }
    return '@';
}