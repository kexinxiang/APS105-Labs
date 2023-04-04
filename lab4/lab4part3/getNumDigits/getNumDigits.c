#include <stdbool.h>
#include <stdio.h>
int getNumDigits(int);
int main(void) {
  int num = 123;
  printf("getNumDigits(%d) = %d\n", num, getNumDigits(num));
  num = 98765421;
  printf("getNumDigits(%d) = %d\n", num, getNumDigits(num));
  num = 76532;
  printf("getNumDigits(%d) = %d\n", num, getNumDigits(num));
  return 0;
}
int getNumDigits(int num) {
  int count = 0;
  while (num > 0) {
    num = num / 10;
    count++;
  }
  return count;
}
