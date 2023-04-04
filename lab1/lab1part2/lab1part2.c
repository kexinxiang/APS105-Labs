#include <stdio.h>
int main(void){
    double rate;
    double amount;
    printf("Enter the conversion rate: ");
    scanf("%lf", &rate);
    printf("Enter the amount to be converted (in foreign currency): ");
    scanf("%lf", &amount);
    double canadianAmount = rate * amount;
    printf("The amount in Canadian Dollars is: %.2lf", canadianAmount);
    return 0;
}
