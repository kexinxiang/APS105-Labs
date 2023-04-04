/**
* @file reversi.c
* @author <-- Alissa Xiang-->
* @brief This file is used for APS105 Lab 8. 2023W version
* @date 2023-03-14
*
*/
// DO NOT REMOVE THE FOLLOWING LINE
#if !defined(TESTER_P1) && !defined(TESTER_P2)
// DO NOT REMOVE THE ABOVE LINE
#include "reversi.h"
#include <stdio.h>
// DO NOT REMOVE THE FOLLOWING LINE
#endif
// DO NOT REMOVE THE ABOVE LINE
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

bool isValidMove(char board[][26], int n, char colour, int row, int col){
    bool valid = false;
    for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            if(!(i==0 && j==0) && checkLegalInDirection(board, n, row, col, colour, i, j)){
                valid = true;
            }
        }
    }
    return valid;
}

bool moveAvailable(char board[][26], int n, char colour){
    bool available = false;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(isValidMove(board, n, colour, i, j)){
                available = true;
            }
        }
    }
    return available;
}

int makeMove(char board[26][26], int n, char turn, int *row, int *col) {
    int score = 0, scoreMax = 0, bestRow, bestCol;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isValidMove(board, n, turn, i, j)){
                int rowCopy = i;
                int colCopy = j;
                for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                    for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                        if(!(deltaRow == 0 && deltaCol == 0) && checkLegalInDirection(board, n, i, j, turn, deltaRow, deltaCol)){
                            do{
                                rowCopy += deltaRow;
                                colCopy += deltaCol;
                                score++;
                            }while(board[rowCopy][colCopy] != turn);
                            rowCopy = i;
                            colCopy = j;
                            score = score - 1;
                        }
                    }
                }
                if(score > scoreMax){
                    scoreMax = score;
                    bestRow = i;
                    bestCol = j;
                }
                score = 0;
            }  
        }
    }
    *row = bestRow;
    *col = bestCol;
}

//*******************************************************
// Note: Please only put your main function below
// DO NOT REMOVE THE FOLLOWING LINE
#ifndef TESTER_P2
// DO NOT REMOVE THE ABOVE LINE
int main(void) {
// Write your own main function here
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

    char compColour;
    printf("Computer plays (B/W): ");
    scanf(" %c", &compColour);
    printBoard(board, n);

    char row, col, turnColour, userColour, boardcopy;
    int bestRow, bestCol;
    bool invalidMove = false;
    
    if(compColour == 'W'){
        userColour = 'B';
    }else{
        userColour = 'W';
    }

    turnColour = 'B';

    while(moveAvailable(board, n, userColour) || moveAvailable(board, n, compColour)){
        if(turnColour == userColour){
            if(!moveAvailable(board, n, userColour)){
                printf("%c player has no valid move.\n", userColour);
                turnColour = compColour;
            }else{
                printf("Enter move for colour %c (RowCol): ", userColour);
                scanf(" %c%c", &row, &col);
                int rownum = row - 'a';
                int colnum = col - 'a';
                if(!isValidMove(board, n, userColour, rownum, colnum)){
                    printf("Invalid move.\n");
                    invalidMove = true;
                    break;
                }
                //flip colours
                for(int i = -1; i<=1; i++){
                    for(int j = -1; j<=1; j++){
                        if(!(i == 0 && j == 0) && checkLegalInDirection(board, n, row - 'a', col - 'a', userColour, i, j)){
                            do{
                                rownum = rownum + i;
                                colnum = colnum + j;
                                boardcopy = board[rownum][colnum];
                                board[rownum][colnum] = userColour;
                            }while(boardcopy != userColour);
                            rownum = row - 'a';
                            colnum = col - 'a';
                        }    
                    }      
                }
                //update placed position
                board[row-'a'][col-'a'] = userColour;
                turnColour = compColour;
                printBoard(board, n);
            }
        }else{
            if(!moveAvailable(board, n, compColour)){
                printf("%c player has no valid move.\n", compColour);
                turnColour = userColour;
            }else{
                makeMove(board, n, compColour, &bestRow, &bestCol);
                int bestRowCopy = bestRow, bestColCopy = bestCol;
                for(int i = -1; i<=1; i++){
                    for(int j = -1; j<=1; j++){
                        if(!(i == 0 && j == 0) && checkLegalInDirection(board, n, bestRow, bestCol, compColour, i, j)){
                            do{
                                bestRow += i;
                                bestCol += j;
                                boardcopy = board[bestRow][bestCol];
                                board[bestRow][bestCol] = compColour;
                            }while(boardcopy != compColour);
                            bestRow = bestRowCopy;
                            bestCol = bestColCopy;
                        }    
                    }      
                }
                board[bestRow][bestCol] = compColour;
                printf("Computer places %c at %c%c.\n", compColour,'a'+ bestRow, 'a' + bestCol);
                turnColour = userColour;
                printBoard(board, n);
            }
        } 
    }
    
    if(invalidMove){
        printf("%c player wins.\n", compColour);
        return 0;
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'B'){
                count++;
            }
        }
    }

    if(count > n*n/2){
        printf("B player wins.\n");
    }else if(count == n*n){
        printf("Draw.\n");
    }else{
        printf("W player wins.\n");
    }

    return 0;
}
// DO NOT REMOVE THE FOLLOWING LINE
#endif

// DO NOT REMOVE THE ABOVE LINE
//*******************************************************
