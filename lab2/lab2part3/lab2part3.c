#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void){

    double bodyWeight, height, BMI;
    char weightUnit[3];
    char heightUnit[3];
    printf("Enter the body weight: ");
    scanf("%lf%s", &bodyWeight, weightUnit);

    printf("Enter the height: ");
    scanf("%lf%s", &height, heightUnit);

    
    if(strcmp(weightUnit, "lb")==0){
        bodyWeight = bodyWeight * 0.4536;
    }

    if(strcmp(heightUnit, "ft")==0){
        height = height/3.28;
    }
    if(strcmp(heightUnit, "in")==0){
        height = height / 39.37;
    }

    BMI = bodyWeight/pow(height,2);
    printf("\nThe Body Mass Index (BMI) is: %.1lf\n", BMI);

    BMI = rint(BMI * 10)/10;

    if(BMI < 18.5){
        printf("Category: Underweight");
        return 0;
    }else if(BMI <= 24.9){
        printf("Category: Healthy Weight");
        return 0;
    }else if(BMI <= 29.9 ){
        printf("Category: Overweight");
        return 0;
    }else{
        printf("Category: Obesity");
    }

    return 0;
}
