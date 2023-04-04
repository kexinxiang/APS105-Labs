#include <stdbool.h>
#include <stdio.h>
void calculateScore(int[], const int, int[], int[], const int, int*,
                    int*);  // calculate the score of each user
int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  printf("Enter boxes content: ");
  for (int i = 0; i < BoxesNum; i++) {
    scanf("%d", &boxes[i]);
  }
  printf("Enter player 1 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userOne[i]);
  }
  printf("Enter player 2 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userTwo[i]);
  }
  int userOneScore = 0, userTwoScore = 0;
  calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore,
                 &userTwoScore);
  printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);
  return 0;
}
void calculateScore(int boxes[], const int BoxesNum, int userOne[], int userTwo[], const int ChoicesNum, int* score1, int* score2) {

    bool foundOne = false, foundTwo = false;

    for(int i = 0; i<BoxesNum; i++){
        if(boxes[i] == 10){
            printf("Found 10 in boxes[%d].\n", i);
            for(int j = 0; j<ChoicesNum; j++){
                if(userOne[j] == i){
                    foundOne = true;
                }
                if(userTwo[j] == i){
                    foundTwo = true;
                }
            }
            if(foundOne && !foundTwo){
                printf("Found index %d in player 1.\n", i);
                printf("+10 to player 1 score.\n");
                *score1 += 10;
            }else if(foundTwo && !foundOne){
                printf("Found index %d in player 2.\n", i);
                printf("+10 to player 2 score.\n");
                *score2 += 10;
            }else if(foundOne && foundTwo){
                printf("Found index %d in player 1.\n", i);
                printf("Found index %d in player 2.\n", i);
                printf("+5 to players 1 and 2 scores.\n");
                *score1 += 5;
                *score2 += 5;
            }
        }
        if(boxes[i] == -10){
            printf("Found -10 in boxes[%d].\n", i);
            for(int j = 0; j<ChoicesNum; j++){
                if(userOne[j] == i){
                    foundOne = true;
                }
                if(userTwo[j] == i){
                    foundTwo = true;
                }
            }
            if(foundOne && !foundTwo){
                printf("Found index %d in player 1.\n", i);
                printf("-10 from player 1 score.\n");
                *score1 -= 10;
            }else if(foundTwo && !foundOne){
                printf("Found index %d in player 2.\n", i);
                printf("-10 from player 2 score.\n");
                *score2 -= 10;
            }else if(foundOne && foundTwo){
                printf("Found index %d in player 1.\n", i);
                printf("Found index %d in player 2.\n", i);
                printf("-10 from player 1 score.\n");
                printf("-10 from player 2 score.\n");
                *score1 -= 10;
                *score2 -= 10;
            }

        }
        foundOne = false, foundTwo = false;
    }
}
