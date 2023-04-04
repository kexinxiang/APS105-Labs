#include <stdio.h>
#include <math.h>

int getAscendingOrderedDigits(int number);
int descend(int num);

int main(){

    int num, ascendNum, descendNum;

    do{
        int count = 0;
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);

        if(num == -1){
            break;
        }
        
        if(num > 9999 ){
            printf("Error: the number is too large.\n");
        }else if(num < 1000){
            printf("Error: the number is too small.\n");
        }else if(num == 6174){
            printf("Number %d: %d\n", count+1, num);
            printf("Kaprekar's Constant was reached in %d iteration(s).\n", count);
        }else{
            int diff;
            do{
                ascendNum = getAscendingOrderedDigits(num);
                descendNum = descend(ascendNum);
                diff = descendNum - ascendNum;
                count++;
                printf("Number %d: %d\n", count, num);
                num = diff;
            }while(diff != 6174);
            printf("Number %d: %d\n", count+1, num);
            printf("Kaprekar's Constant was reached in %d iteration(s).\n", count);
        }
    }while(num != -1);
    
    return 0;

}

int getAscendingOrderedDigits(int number) {
    int digits[10] = {0};
    while (number > 0) {
        digits[number % 10]++;
        number /= 10;
    }
    
    int i = 0;
    
    while (i < 10) {
        if (digits[i] > 0) {
            number *= 10;
            number += i;
            digits[i]--;
        } else {
            i++;
        }
    }
    return number;
}

int descend(int num){
    int digit, a = 3, sum;
    while(num != 0){
        digit = num % 10;
        num /= 10;
        sum = sum + digit * pow(10,a);
        a--;
    } 
    return sum;
}

