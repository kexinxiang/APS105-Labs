#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int BasetoBase(int number, int baseNum1, int baseNum2){
    int digit;
    int sum1 = 0;
    int sum2 = 0; 
    int n = 0; 
    int a = 0;
    while(number>0){
        digit = number %10;
        number = number/10;
        sum1 = sum1 + digit * pow(baseNum1, n);
        n++;
    }
    while(sum1>0){
        digit = sum1 % baseNum2;
        sum1 = sum1 / baseNum2;
        sum2 = sum2 + digit * pow(10,a);
        a++;
    }
    return sum2; 
}

bool checkdigit(int num, int baseNumber){
    int d; 
    bool invalid;
    while(num >0){
        d = num %10;
        if(d >= baseNumber){
            return true;
        }else{
            invalid = false;
        }
        num = num/10;
    }
    return invalid;
}

int main(){
    char oprt;
    int inBase, num1, num2, outBase, num1Base10, num2Base10, sum;
    
    
    do{
        printf("Give input ($ to stop): ");
        scanf(" %c %d %d %d %d", &oprt, &inBase, &num1, &num2, &outBase);

        if(oprt == '$'){
            break;
        }
        if(oprt != '+' && oprt != '-' && oprt != '*' && oprt != '/'&& oprt != '$'){
            printf("Invalid operator\n");
        }else if(inBase < 2 || inBase >10 || outBase <2 || outBase >10){
            printf("Invalid base\n");
        }else if(checkdigit(num1, inBase) || checkdigit(num2, inBase)){
            printf("Invalid digits in operand\n");
        }else{
            
            num1Base10 = BasetoBase(num1, inBase, 10);
            num2Base10 = BasetoBase(num2, inBase, 10);
            
            if(oprt == '+'){
                sum = BasetoBase((num1Base10 + num2Base10),10,outBase);
            }else if (oprt == '-'){
                sum = BasetoBase((num1Base10 - num2Base10),10, outBase);
            }else if (oprt == '*'){
                sum = BasetoBase((num1Base10 * num2Base10),10, outBase);
            }else{
                sum = BasetoBase((num1Base10 / num2Base10),10, outBase);
            }

            printf("%d %c %d (base %d) = %d %c %d = %d (base %d)\n", num1, oprt, num2, inBase, num1Base10, oprt, num2Base10, sum, outBase);
        }
    }while(oprt != '$');

    return 0;
}
