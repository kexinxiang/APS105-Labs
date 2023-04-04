//
// Author: Alissa
//

#include "reversi.h"

#include <stdbool.h>
#include <stdio.h>

void printBoard(char board[][26], int n) {

    for(int i = -1; i<n; i++){
        for(int j = -1; j<n; j++){
            if(i == -1 && j == -1){
                printf("  ");
            }else if(i == -1 && j != -1){
                printf("%c", 'a'+j);
            }else if(j == -1 & i != -1){
                printf("%c%c", 'a'+i, ' ');
            }else{
                printf("%c", board[i][j]);
            }
        }
        printf("\n");  
    }
}

bool positionInBounds(int n, int row, int col) {
  bool inbound = false;
  if (row >= 0 && row <= n - 1 && col >= 0 && col <= n - 1) {
    inbound = true;
  }
  return inbound;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    bool legal = false;
    int count = 0;
    char oppColour = '\0';

    if(colour == 'W'){
        oppColour = 'B';
    }else{
        oppColour = 'W';
    }

    if(board[row][col] == 'U'){
        while(board[row][col] != colour){
            if (positionInBounds(n, row, col)) {
                //update according to direction
                row = row + deltaRow;
                col = col + deltaCol;
                if(board[row][col] == 'U'){
                    return false;
                }
                if(board[row][col] == oppColour){
                    count++;
                }
                if(count >= 1 && board[row][col] == colour && positionInBounds(n, row, col)){
                    legal = true;
                    break;
                }
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
    return legal;
}

int main(void) {

    int n;

    printf("Enter the board dimension: ");
    scanf("%d", &n);

    char board[26][26] = {};

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            board[row][col] = 'U';
        }
    }

    board[n / 2-1][n / 2-1] = 'W';
    board[n / 2 ][n / 2-1] = 'B';
    board[n / 2-1][n / 2 ] = 'B';
    board[n / 2 ][n / 2] = 'W';

    printBoard(board, n);

    char colour = '\0', row = '\0', col = '\0';
    printf("Enter board configuration: ");

    while (colour != '!') {
        scanf(" %c%c%c", &colour, &row, &col);
        int i = row - 'a';
        int j = col - 'a';
        board[i][j] = colour;
    }
    printBoard(board, n);

    
    printf("Available moves for W: \n");
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(checkLegalInDirection(board, n, i, j, 'W', 1, 0)||checkLegalInDirection(board, n, i, j, 'W', -1, 0)||
            checkLegalInDirection(board, n, i, j, 'W', 0, 1)||checkLegalInDirection(board, n, i, j, 'W', 0, -1)||
            checkLegalInDirection(board, n, i, j, 'W', -1, 1)||checkLegalInDirection(board, n, i, j, 'W', 1, -1)||
            checkLegalInDirection(board, n, i, j, 'W', -1, -1)||checkLegalInDirection(board, n, i, j, 'W', 1, 1)){
                printf("%c%c\n", i+'a', j+'a');
            }
        }
    }
    
    printf("Available moves for B: \n");
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(checkLegalInDirection(board, n, i, j, 'B', 1, 0)||checkLegalInDirection(board, n, i, j, 'B', -1, 0)||
            checkLegalInDirection(board, n, i, j, 'B', 0, 1)||checkLegalInDirection(board, n, i, j, 'B', 0, -1)||
            checkLegalInDirection(board, n, i, j, 'B', -1, 1)||checkLegalInDirection(board, n, i, j, 'B', 1, -1)||
            checkLegalInDirection(board, n, i, j, 'B', -1, -1)||checkLegalInDirection(board, n, i, j, 'B', 1, 1)){
                printf("%c%c\n", i+'a', j+'a');
            }
        }
    }

    printf("Enter a move: ");
    scanf(" %c%c%c", &colour, &row, &col);

    int rownum = row - 'a', colnum = col - 'a';
    bool valid = false;
    char boardcopy = '\0';

    for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            if(!(i == 0 && j == 0) && checkLegalInDirection(board, n, rownum, colnum, colour, i, j)){
                valid = true;
                do{
                    rownum = rownum + i;
                    colnum = colnum + j;
                    boardcopy = board[rownum][colnum];
                    board[rownum][colnum] = colour;
                }while(boardcopy != colour);
                rownum = row - 'a';
                colnum = col - 'a';
            }
        }
    }

    if(valid){
        board[rownum][colnum] = colour;
        printf("Valid move.\n");
        printBoard(board, n);
    }

    if(!valid){
        printf("Invalid move.");
        printBoard(board, n);
    } 

    return 0;
}
