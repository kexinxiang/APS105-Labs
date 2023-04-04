#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  char operator;
  int base1, num1, num2, base2;
  do {
    printf("Give input ($ to stop): ");
    scanf(" %c %d %d %d %d", &operator, & base1, &num1, &num2, &base2);

    bool invaliDigit = false;
    int checknum1 = num1;
    int digit1 = 0, sum1 = 0, count1 = 0;
    while (checknum1 > 0) {
      digit1 = checknum1 % 10;
      checknum1 = checknum1 / 10;
      if (digit1 >= base1) {
        invaliDigit = true;
        break;
      }
      sum1 = sum1 + digit1 * pow(base1, count1);
      count1++;
    }

    int checknum2 = num2;
    int digit2 = 0, sum2 = 0, count2 = 0;
    while (checknum2 > 0) {
      digit2 = checknum2 % 10;
      checknum2 = checknum2 / 10;
      if (digit2 >= base1) {
        invaliDigit = true;
        break;
      }
      sum2 = sum2 + digit2 * pow(base1, count2);
      count2++;
    }

    if (operator== '$') {
      break;
    } else if (!(operator == '+' || operator == '-' || operator == '*' || operator == '/')) {
      printf("Invalid operator\n");
    } else if (!(base1 >= 2 && base1 <= 10) || !(base2 >= 2 && base2 <= 9)) {
      printf("Invalid base\n");
    } else if (invaliDigit) {
      printf("Invalid digits in operand\n");
    } else {
      int result = 0;
      if (operator == '+') {
        result = sum1 + sum2;

      } else if (operator == '-') {
        result = sum1 - sum2;

      } else if (operator == '*') {
        result = sum1 * sum2;

      } else if (operator == '/') {
        result = sum1 / sum2;
      }
      int answer = 0, count = 0;
      while (result > 0) {
        answer = answer + (result % base2) * pow(10, count);
        result = result / base2;
        count++;
      }
      printf("%d %c %d (base %d) = %d %c %d = %d (base %d)\n", num1, operator, num2, base1,
             sum1, operator, sum2, answer, base2);
    }
  } while (operator!= '$');

  return 0;
}
