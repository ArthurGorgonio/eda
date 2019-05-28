#include <stdlib.h>
#include <sys/time.h>
#include "common.h"
#include "insertion.h"
#include "merge.h"
#include "mergeHybrid.h"

/*
 * ============================================================================
 *
 *       Filename:  mergeHybrid.c
 *
 *    Description:  This file contains the functions to sort a float vector with
 *        merge sort and insertion sort algorithms.
 *
 *        Version:  1.0
 *        Created:  2019 May 27 23:50 -0300
 *    Last Edited:  2019 May 27 23:50 -0300
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Arthur Gorgônio, gorgonioarthur@gmail.com
 *   Organization:
 *
 * ============================================================================
 */

/*
 * ===  FUNCTION  =============================================================
 *           Name:  hybridMergeSort
 *    Description:  This algorithm is hybrid when called we start using merge
 *        sort algorithm, but when the length of the actual vector is less than
 *        a threshold we change the sort algorithm to insertion sort.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             i => Initial point of the vector.
 *             f => Final point of the vector.
 *     threshold => The threshold to change the sort algorithm to insertion
 *        sort to finish the process.
 *
 *         Return:  void
 * ============================================================================
*/
void hybridMergeSort(float *v, int i, int f, int threshold) {
  if ((f - i + 1) <= threshold) {
    insertionSort(v, (f - i + 1));
  } else {
    int m;
    if (i < f) {
      m = (i + f) / 2;
      hybridMergeSort(v, i, m, threshold);
      hybridMergeSort(v, m + 1, f, threshold);
      merge(v, i, m, f);
    }
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  runmergeHybrid
 *    Description:  This function calls the Merge sort and Insertion sort
 *        algorithms and compute the time spent.
 *
 *         Params:
 *        length => The length of the vector *v
 *   nIterations => How many times the algorithm run.
 *      maxRange => The range of the numbers.
 *
 *         Return: void
 * ============================================================================
*/
void runMergeHybrid(int length, int nIterations, int maxRange) {
  char *archive = "mergeHybrid_10.txt";
  double time = 0.0;
  float *v = (float *) malloc(length * sizeof(float));
  int j;
  struct timeval timeStart, timeStop;
  for (j = 0; j < nIterations; j++) {
    generateValues(v, length, maxRange);
    gettimeofday(&timeStart, NULL);
    hybridMergeSort(v, 0, length, 10);
    gettimeofday(&timeStop, NULL);
    time = computeTime(timeStart, timeStop, time);
  }
  time = time / nIterations;
  writeTime(archive, length, time);
  free(v);
}
