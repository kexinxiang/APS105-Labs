#include <stdio.h>
#include <math.h>

int main(){
    int r; 
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    for(int line = r; line >= -r; line--){
        for(int col = -r; col <= r; col++){
            if(sqrt(col*col + line*line) <= sqrt(r*r)){
                printf("o");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
}
