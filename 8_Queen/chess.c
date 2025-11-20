/*------------------------------------------------------
* Filename: chess.c
* Description: Finds a way to put 8 queens in a chess board.
* Author: Rephael Riahi and Stav Menashe.
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHESS_SIZE 8
#define STARTING_POINTS 14
#define HORIZONTAL_CASE (0)
#define VERTICAL_CASE (1)

typedef struct{
    int row;
    int col;
}Point;

void horizontal_state(int** chess_board);
void vertical_state(int** chess_board);
int find_state(Point point);
int check_point_in_arr(Point state_points[STARTING_POINTS], Point point, int state);

int main() {
    int state = 0;
    Point chess_board[CHESS_SIZE * CHESS_SIZE] = {(0,0)};
    Point choice = (0,0);
    printf("Please choose the square you want to start from:\n"
    "Note: don't choose one of the corners or the central squares.\n");
    scanf_s("%d %d",&choice.row,choice.col);
    if(choice.col < 0 || choice.col >= CHESS_SIZE || choice.row < 0 || choice.row >= CHESS_SIZE){
        printf("Wrong input!");
        return -1;
    }
    state = find_state(choice);
    if(state == HORIZONTAL_CASE){
        horizontal_state(chess_board);
    }else{
        vertical_state(chess_board);
    }
    return 0;
}


int find_state(Point point){
    int index = 0;
    //Point vertical_points[STARTING_POINTS] = {(3,0), (4,0), (1,3), (1,4), (2,3), (2,4), (2,5), (3,6), (3,7), (4,7), (5,3),
    //(5,4), (6,3), (6,4)};
    Point horizontal_points[STARTING_POINTS] = {(0,3), (0,4), (3,1), (4,1), (3,2), (4,2), (5,2), (6,3), (7,3), (7,4), (3,5),
    (4,5), (3,6), (4,6)};
    if (check_point_in_arr(horizontal_points, point, HORIZONTAL_CASE)){
        return HORIZONTAL_CASE;
    }
    return VERTICAL_CASE;
}

int check_point_in_arr(Point state_points[STARTING_POINTS], Point point, int state){
    int index;
    for (index = 0 ; index < STARTING_POINTS ; ++index){
        if (state_points[index].row == point.row && 
            state_points[index].col == point.col){
                return 1;
        }
    }
    return -1;
}

/*------------------------------------------------------
* Function Name - dyn_scanf
*
* Function Purpose - creates an array of char in the size of the user's input and gets a string from the user
*
* Parameters –  void
*
* Return Values - the user's input
*
* Author - Rephael Riahi
-------------------------------------------------------*/