/*------------------------------------------------------
* Filename: change_words.c
* Description: Arranges words in a text file in the following way:
                All the first words in the file are from the first sentence
                in the new order.
                All the second words in the file are from the second sentence
                in the new order. so on.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define MAX_WORD_NUM (100)
#define MAX_WORD_LEN (256)
#define FUNC_SUCCEED (1)
#define WRONG_ARGUMENTS (-1)
#define CANNOT_OPEN_FILE (-2)
#define CANNOT_CLOSE_FILE (-3)
#define CANNOT_DELETE_FILE (-4)

void save_words(char *text);

int main() {
    char str[MAX_WORD_LEN] = {0};
    char *test = "word1 word2 word3 word4 word5";
    save_words(test);
    return 0;
}


void save_words(char *text){
    int index = 0, words_arr_index = 0;
    char curr_char = text[index];
    char curr_word[MAX_WORD_LEN] = {0};
    int word_len = 0;
    char *words_arr[MAX_WORD_NUM];
    int in_word_flag = 0;

    while (curr_char != '\0'){
        if (curr_char == ' '){
            if (in_word_flag){
                in_word_flag = 0;
                words_arr[words_arr_index] = strdup(curr_word);
                words_arr_index += 1;
                curr_word[0] = '\0';
                word_len = 0;
            }
        }
        else if (curr_char == '\n'){}
        else{
            curr_word[word_len] = curr_char;
            word_len += 1;
            curr_word[word_len] = '\0';
            in_word_flag = 1;
        }

        index += 1;
        curr_char = text[index];
    }

    if (in_word_flag){
        words_arr[words_arr_index] = strdup(curr_word);
        words_arr_index++;
    }

    return;
}


int take_file_str(FILE * file_name, char str[MAX_WORD_LEN]){
    FILE *file_p = fopen(file_name, "r");
    int word_len = 0;
    
    int c;

    if (file_p == NULL){
        printf("Could not open %s.\n", file_name);
        fclose(file_name);
        return CANNOT_OPEN_FILE;
    }

    c = fgetc(file_p);

    while (c != EOF) {
        str[word_len] = c;
        word_len += 1;
        c = fgetc(file_p);
    }

    if (fclose(file_p) != 0){
        return CANNOT_CLOSE_FILE;
    }

    return FUNC_SUCCEED;
}