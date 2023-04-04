#include <math.h>
#include <stdio.h>

int main() {
  int radius;
  printf("Enter the radius of the circle: \n");
  scanf(" %d", &radius);

  for (int row = -radius; row <= radius; row++) {
    for (int col = -radius; col <= radius; col++) {
      int x = sqrt(radius * radius - row * row);
      if (col < -x || col > x) {
        printf(".");
      } else {
        printf("o");
      }
    }
    printf("\n");
  }

  return 0;
}
