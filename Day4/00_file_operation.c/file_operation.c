/*------------------------------------------------------
* Filename: file_operations.c
* Description: Prints, copy and deletes lines in a file.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h> /* For isalpha() */

#define FILE_NAME_SIZE (256)
#define SEN_SIZE (256)
#define FUNC_SUCCEED (1)
#define WRONG_ARGUMENTS (-1)
#define CANNOT_OPEN_FILE (-2)
#define CANNOT_CLOSE_FILE (-3)
#define CANNOT_DELETE_FILE (-4)
#define CANNOT_RENAME_FILE (-5)


int fread_and_print(char *file_name);
int fcopy_text(char *file_in_name, char *file_out_name);
int fprint_data(char *file_name);
int fdelete_line(char *file_name, int line);

int main(int argc, char * argv[]) {
    return 0;
}


/*------------------------------------------------------
* Function Name - fread_and_print.
* Function Purpose - read a file and print its contant. 
* Parameters –  file_name - the name of the file.
* Return Values - integer indicates the state of the function.
* Author - Stav Menashe.
-------------------------------------------------------*/
int fread_and_print(char *file_name){
    FILE *file_p = fopen(file_name, "r");
    int c = 0;

    if (file_p == NULL){
        printf("Could not open %s.\n", file_name);
        fclose(file_p);
        return CANNOT_OPEN_FILE;
    }

    c = fgetc(file_p);
    while (c != EOF) {
        fputc(c, stdout);
        c = fgetc(file_p);
    }

    if (fclose(file_p) != 0){
        return CANNOT_CLOSE_FILE;
    }
    return FUNC_SUCCEED;
}


/*------------------------------------------------------
* Function Name - fcopy_text
* Function Purpose - copy the contant of one file to another. 
* Parameters –  file_in_name - the name of the the text is copied from.
                file_out_name - the name of the the text is copied to.
* Return Values - integer indicates the state of the function.
* Author - Stav Menashe.
-------------------------------------------------------*/
int fcopy_text(char *file_in_name, char *file_out_name){
    FILE *file_in_p = fopen(file_in_name, "r");
    FILE *file_out_p = fopen(file_out_name, "a");
    int c = 0;

    if (file_in_p == NULL){
        printf("Could not open %s.\n", file_in_name);
        fclose(file_in_p);
        return CANNOT_OPEN_FILE;
    }

    c = fgetc(file_in_p);

    while (c != EOF) {
        fputc(c, file_out_p);
        c = fgetc(file_in_p);
    }

    if (fclose(file_in_p) != 0 || fclose(file_out_p) != 0){
        return CANNOT_CLOSE_FILE;
    }

    return FUNC_SUCCEED;
}

/*------------------------------------------------------
* Function Name - fprint_data.
* Function Purpose - read a file and print some data about its contant. 
* Parameters –  file_name - the name of the file.
* Return Values - integer indicates the state of the function.
* Author - Stav Menashe.
-------------------------------------------------------*/
int fprint_data(char *file_name){
    FILE *file_p = fopen(file_name, "r");
    int c = 0;
    int prev = 0;
    int countLines = 0, countWords = 0, countLetters = 0;

    if (file_p == NULL){
        printf("Could not open %s.\n", file_name);
        fclose(file_p);
        return CANNOT_OPEN_FILE;
    }

    c = fgetc(file_p);
    prev = ' ';

    while (c != EOF) {
        if (c == '\n'){
            countLines += 1;
        }
        if (isalpha(c)){
            if((prev == ' ') || (prev == '\n')){
                countWords += 1;  
            }
            countLetters += 1;
        }
        prev = c;
        c = fgetc(file_p);
    }

    printf("%d\n%d\n%d\n", countLines, countWords, countLetters);

    if (fclose(file_p) != 0){
        return CANNOT_CLOSE_FILE;
    }

    return FUNC_SUCCEED;
}


/*------------------------------------------------------
* Function Name - fdelete_line.
* Function Purpose - delete a line from a file.
* Parameters –  file_name - the name of the file.
                line - the line number to delete from the file.
* Return Values - integer indicates the state of the function.
* Author - Stav Menashe.
-------------------------------------------------------*/
int fdelete_line(char *file_name, int line){
    FILE *file_p = fopen(file_name, "r");
    FILE *file_temp = fopen("temp_file", "a");

    char buffer[SEN_SIZE];
    int current_line = 0;

    if (file_p == NULL){
        printf("Could not open %s.\n", file_name);
        fclose(file_p);
        return CANNOT_OPEN_FILE;
    }

    while (fgets(buffer, sizeof(buffer), file_p) != NULL) {
        current_line += 1;
        if (current_line != line) {
            fprintf(file_temp, "%s", buffer);
        }
    }

    if (fclose(file_p) != 0){
        return CANNOT_CLOSE_FILE;
    }
    if (fclose(file_temp) != 0){
        return CANNOT_CLOSE_FILE;
    }

    if (remove(file_name) != 0) {
        perror("Error deleting original file");
        return CANNOT_DELETE_FILE;
    }

    if (rename("temp_file", file_name) != 0) {
        perror("Error renaming temp file");
        return CANNOT_RENAME_FILE;
    }

    return FUNC_SUCCEED;
}