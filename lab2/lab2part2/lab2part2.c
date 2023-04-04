#include <stdio.h>

int main(void){

    double x, y;
    printf("Enter the x-coordinate in floating point: ");
    scanf("%lf", &x);
    printf("Enter the y-coordinate in floating point: ");
    scanf("%lf", &y);

    if (x==0){
        if(y==0){
            printf("(0.00, 0.00) is at the origin.");
            //return 0;
        }else{
            printf("(0.00, %.2lf) is on the y axis.", y);
            //return 0;
        }
    }

    if(y==0){
        printf("(%.2lf, 0.00) is on the x axis.", x);
        //return 0;
    }

    if(x>0){
        if(y>0){
            printf("(%.2lf, %.2lf) is in quadrant I.", x, y);
        }else if (y!=0){
            printf("(%.2lf, %.2lf) is in quadrant IV.", x, y);
        }
    }else if(x<0){
        if(y>0){
            printf("(%.2lf, %.2lf) is in quadrant II.", x, y);
        }else if(y!=0){
            printf("(%.2lf, %.2lf) is in quadrant III.", x, y);
        }
    }
    return 0;
}
