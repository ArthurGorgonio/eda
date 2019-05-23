#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main() {
  int *v, i, n;
  printf("Quantos elementos o vetor possui? ");
  scanf("%d",&n);
  v = (int *) malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    printf("elemento %d \n", (i + 1));
    scanf("%d",&v[i]);
  }
  heapsort(v, n);
  printf("\nApós HEAP sort!\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", v[i]);
  }
  printf("\n");
  return 0;
}
