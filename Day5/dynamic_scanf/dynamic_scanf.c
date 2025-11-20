/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: Gets an input from the user and prints it.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define ADD_CHAR (1)
#define EMPTY_STRING ("")

char* dyn_scanf(void);
void error_eof();
void error_no_space(void);
void error_too_much_input(void);

int main() {
    char *text = dyn_scanf();
    printf_s("your text: %s", text);
    free(text);
    return 0;
}

char* dyn_scanf(void){
    char *text = NULL;
    char *tmp_text = NULL;
    size_t size = 0;
    size_t len = 0;

    printf_s("Write a line of text: ");
    unsigned int curr_ch = getchar();

    while(curr_ch != '\n' && curr_ch != EOF){
        if (text == NULL) {
            size = ADD_CHAR; /*for '\0'*/
            text = malloc(size + ADD_CHAR); 
            if (text == NULL) {
                return EMPTY_STRING;
            }
        }

        if (len == SIZE_MAX) {
            error_too_much_input();
            return text;
        }

        if (len + 1 >= size) {
            if (size >= SIZE_MAX - ADD_CHAR) {
                error_too_much_input();
                return text;
            }
            size += ADD_CHAR;
            tmp_text = realloc(text, size + 1);
            if (tmp_text == NULL) {
                free(text);
                error_no_space();
                return EMPTY_STRING;
            }
            text = tmp_text;
        }
        
        text[len] = curr_ch;
        len++;

        curr_ch = getchar();
    }

    if (text == NULL) {
        if (curr_ch == EOF)
            error_eof();
        return EMPTY_STRING; 
    }

    text[len] = '\0';
    return text;
}


/*------------------------------------------------------
* Function Name - error_eof
* Function Purpose - Prints an error msg for EOF case.
* Parameters –
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void error_eof(void){
    printf_s("Error: eof\n");
    return;
}

/*------------------------------------------------------
* Function Name - error_no_space
* Function Purpose - Prints an error msg for no space left.
* Parameters –
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void error_no_space(void){
    printf_s("Error: No space left");
    return;
}

/*------------------------------------------------------
* Function Name - error_too_much_input
* Function Purpose - Prints an error msg for too much input.
* Parameters –
* Return Values -
* Author - Stav Menashe
-------------------------------------------------------*/
void error_too_much_input(void){
    printf_s("Error: input too long\n");
}