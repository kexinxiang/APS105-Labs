#include <stdio.h>

int main(void){

    int baseTenNum;
    printf("Enter number to convert to base 2:");
    scanf("%d", &baseTenNum);

    int leastSig = baseTenNum%2;
    int firstDiv = baseTenNum/2;
    int secLastDig = firstDiv%2;
    int secDiv = firstDiv/2;
    int thirdLastDig = secDiv%2;
    int thirdDiv = secDiv/2;
    int mostSig = thirdDiv%2;

    printf("The four digits of that number are as follows:\n");
    printf("Most significant digit: %d\n", mostSig);
    printf("Next digit: %d\n", thirdLastDig);
    printf("Next digit: %d\n", secLastDig);
    printf("Least significant digit: %d", leastSig);
    
    return 0;
}
