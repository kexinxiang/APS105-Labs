#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size, char userArray[][Size]);

void getInput(int* row, int* col, int Size);
void getLevelAndDimensions(int* size, int* difficultyLevel, const int maxDim);
int getRand(int maxChoices);

int main(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;

  getLevelAndDimensions(&Size, &difficultyLevel, maxDim);

  int copy[maxDim][maxDim] = {
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
      {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
      {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}};

  char grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col] + '0';
    }
  }
  // TODO: check if there is a valid game, if not, create one

  while(!gameStatus(Size, grid, difficultyLevel)){
    int row = getRand(Size);
    int col = getRand(Size);
    grid[row][col] = '1';
  }

  int userInputRow = 0, userInputCol = 0;

  // test gameStatus
  char userArray[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      userArray[row][col] = '-';
    }
  }
  bool gameOver = true;
  int steps = 0;
  do {
    getInput(&userInputRow, &userInputCol, Size);
    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);

    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  if (steps == Size * Size) {
    printf("Not a valid game!");
  } else {
    printf("Game over!\n");
    printf("Your score is %d", Size * Size - steps);
  }

  return 0;
}

bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) {
  // you will need to call calculateScoreInDir
  bool gameEnd = false;
    for(int i = 0; i<Size; i++){
        for(int j = 0; j<Size; j++){
            int dir = 0;
            while(dir <= 3){
                if(calculateScoreInDir(i, j, dir, Size, userArray) == difficultyLevel){
                    gameEnd = true;
                }
                dir++;
            }
        }
    }
    return gameEnd;
}

int calculateScoreInDir(int row, int col, int direction, int Size, char userArray[][Size]) {
    if(userArray[row][col] == '0'){
        return 0;
    } 

    int count1 = 0, rowcopy = row, colcopy = col;

    while(userArray[row][col] == '1'){
        if(validRowCol(row, col, Size)){
            count1++;
            updateRowCol(&row, &col, direction, true);
        }else{
            break;
        }
    }

    while(userArray[rowcopy][colcopy] == '1'){
        if(validRowCol(rowcopy, colcopy, Size)){
            count1++;
            updateRowCol(&rowcopy, &colcopy, direction, false);
        }else{
            break;
        }
    }

    return count1-1;
}

bool validRowCol(int row, int col, int Size) {
    int valid = false; 
    if(row >= 0 && row <= Size - 1 && col >= 0 && col <= Size -1){
        valid = true;
    }
    return valid;
}

void updateRowCol(int* row, int* col, int dir, bool forward) {
    if(forward){
        if(dir == 0){
            (*row)--;
        }else if(dir == 1){
            (*row)--;
            (*col)++;
        }else if(dir == 2){
            (*col)++;
        }else if(dir == 3){
            (*row)--;
            (*col)--;
        }
    }else {
        if(dir == 0){
            (*row)++;
        }else if(dir == 1){
            (*row)++;
            (*col)--;
        }else if(dir == 2){
            (*col)--;
        }else if(dir == 3){
            (*row)++;
            (*col)++;
        }
    }
}

void printBoard(int Size, char grid[][Size]) {
    for(int i = 0; i<Size; i++){
    for(int j = 0; j<Size; j++){
        printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

void getInput(int* row, int* col, int Size) {
    printf("Enter user input: ");
    scanf("%d %d", row, col);
    while(!validRowCol(*row, *col, Size)){
        printf("Please enter your row and col to be between 0 and Size - 1: ");
        scanf("%d %d", row, col);
    }
}

void getLevelAndDimensions(int* Size, int* levelOfDiff, const int maxDim) {
    printf("Enter the difficulty level: ");
    scanf("%d", levelOfDiff);

    while(*levelOfDiff < 1 || *levelOfDiff >= maxDim){
        printf("Please enter a difficulty level between 1 and 23: ");
        scanf("%d", levelOfDiff);
    }

    printf("Enter the dimension of the grid: ");
    scanf("%d", Size);

    while(*Size < *levelOfDiff || *Size >= maxDim){
        printf("Please enter dimensions >= %d: ", *levelOfDiff);
        scanf("%d", Size);
    }
}

int getRand(int maxChoices) { 

    return (rand() % (maxChoices)); 

}
