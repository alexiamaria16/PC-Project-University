#include <stdio.h>

#include <stdlib.h>

int findMin(int * v, int n) {
  if (n == 1) {
    return v[0];
  }
  int min = findMin(v, n - 1);
  return (v[n - 1] < min) ? v[n - 1] : min;
}

int findMax(int * v, int n) {
  if (n == 1) {
    return v[0];
  }
  int max = findMax(v, n - 1);
  return (v[n - 1] > max) ? v[n - 1] : max;
}

int main() {
  int v[1000], n;
  printf("Introduceti numarul de elemente din array: ");
  scanf("%d", & n);
  printf("Introduceti elementele din array: \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", & v[i]);
  }

  int minn = findMin(v, n);
  int maxx = findMax(v, n);

  printf("\nMinimum Value: %d\n", minn);
  printf("Maximum Value: %d\n", maxx);

  return 0;
}
