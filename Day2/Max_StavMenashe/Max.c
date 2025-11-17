/*------------------------------------------------------
* Filename: Max.c
* Description: finds the maximum number between two numbers in 4 lines.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>
int main() {
    int x = 10;
    int y = 12;
    /*if x is bigger or equal to y than (x >= y)* x = x. same for y.*/
    int z = (x >= y)* x + (y > x)*y; 
    printf("The maximum number between x and y is : %d", z);

    return 0;
}