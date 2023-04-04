#include <stdio.h>
#include <math.h>

int main(){

    int order, a, b, c, d;

    do{
        printf("Enter the order of the function: ");
        scanf("%d", &order);
        
        if(order == -1){
            break;
        }else if( order>3 || order < 0){
            printf("The order must be between [0, 3].\n");
        }else{
            int coef[4] = {0,0,0,0};
            for(int i = 0; i<=order; i++){
                printf("Enter coefficient of x^%d: ", i);
                scanf("%d", &coef[i]);
            }

            a = coef[0];
            b = coef[1];
            c = coef[2];
            d = coef[3];

            for(int line = 10; line>=-10; line--){
                for(int col = -10; col<=10; col++){
                    if(line == d*pow(col, 3)+c*pow(col, 2)+b*pow(col, 1)+a){
                        printf(" * ");
                    }else if(col==0){
                        printf(" | ");
                    }else if(line == 0){
                        printf(" - ");
                    }else{
                        printf("   ");
                    }
                }   
                printf("\n");  
            }
        }
    }while(order != -1);  
    return 0;
}
