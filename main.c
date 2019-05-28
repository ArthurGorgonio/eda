#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "mergeHybrid.h"
#include "quick.h"
#include "quickHybrid.h"

int main(int argc, char *argv[]) {
  int start, stop, step, nIterations, maxRandomRange, length;
  start = atoi(argv[1]);
  stop = atoi(argv[2]);
  step = atoi(argv[3]);
  nIterations = atoi(argv[4]);
  maxRandomRange = atoi(argv[5]);
  for (length = start; length <= stop; length = length + step) {
    runHeap(length, nIterations, maxRandomRange);
    printf("\nHeap %d", length);
    runInsertion(length, nIterations, maxRandomRange);
    printf("\nInsertion %d", length);
    runMerge(length, nIterations, maxRandomRange);
    printf("\nMerge %d", length);
    runMergeHybrid(length, nIterations, maxRandomRange);
    printf("\nMerge Hybrid %d", length);
    runQuick(length, nIterations, maxRandomRange);
    printf("\nQuick %d", length);
    runQuickHybrid(length, nIterations, maxRandomRange);
    printf("\nQuick Hybrid %d", length);
  }
  return 0;
}
