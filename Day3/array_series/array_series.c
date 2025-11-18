/*------------------------------------------------------
* Filename: array_series.c
* Description: Check the type of a given array.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h> 
#include <stdbool.h> /*For boolean expressions*/
#include <stdlib.h> /*For atoi function*/
#include <string.h> /*For strtok function*/

#define ARR_SIZE (15)
#define START_INDEX (0)
#define MAX_INPUT_LEN (256)

int main() {
    int userArr[ARR_SIZE];
    char userInput[MAX_INPUT_LEN];
    int index, curr, arrIndex;
    bool check_decrease = true; /*A flag for cheking if the array is a descending array*/
    bool check_increase = true; /*A flag for cheking if the array is a increasing array*/
    bool check_constant = true; /*A flag for cheking if the array is a constant array*/

    printf("Insert the test array (an array of 15 integers): ");
    fgets(userInput, sizeof(userInput), stdin);
    arrIndex = 0;
    char *num = strtok(userInput, " ");
    /*Puting the given integers inside an array.*/
    while(arrIndex < ARR_SIZE){
        userArr[arrIndex] = atoi(num);
        ++arrIndex;
        num = strtok(NULL, " ");
    }

    int prev = userArr[START_INDEX];
    for (index = 1 ; index < ARR_SIZE ; ++index){
        curr = userArr[index];
        /*If two items in the array are increasing, the array can't be decreasing or constant.*/
        if (curr > prev){
            check_decrease = false;
            check_constant = false;
        }
        /*If two items in the array are decreasing, the array can't be increasing or constant.*/
        if (curr < prev){
            check_increase = false;
            check_constant = false;
        }
        /*If two items in the array are equals, the array can't be decreasing or increasing.*/
        if (curr == prev){
            check_decrease = false;
            check_increase = false;
        }
        prev = curr;
    }
    if (check_decrease){
        printf("The array is decreasing");
    }
    else if (check_increase){
        printf("The array is increasing");
    }
    else if (check_constant){
        printf("The array is constant");
    }
    else{
        printf("The array is messed up");
    }
    return 0;
}