#include <stdio.h>
#include <math.h>

int main(void){
    double x, y, H, theta;
    printf("Enter X: ");
    scanf("%lf", &x);
    printf("Enter Y: ");
    scanf("%lf", &y);
    H = sqrt(pow(x,2)+pow(y,2));
    theta = asin(y/H) * (180/M_PI);
    printf("The Hypotenuse Length is: %.1lf\n", H);
    printf("The Angle Theta is: %.1lf degrees", theta);

    return 0;
}
