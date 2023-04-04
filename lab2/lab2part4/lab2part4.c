#include <stdio.h>

int main(void) {
  int encComb;
  printf("Enter an encrypted 4-digit combination: ");
  scanf("%d", &encComb);

  // Determine the 4 digits of the encrypted combination.
  int d4, d3, d2, d1;
  d4 = encComb / 1000;
  encComb = encComb % 1000;
  d3 = encComb / 100;
  encComb = encComb % 100;
  d2 = encComb / 10;
  encComb = encComb % 10;
  d1 = encComb;

  // printing the decrypted combination: d4 and d1 are swapped. d3 and d2 are
  // are 9's complemented
  printf("\nThe real combination is: %d%d%d%d\n", d1, 9 - d3, 9 - d2, d4);

  return 0;
}
