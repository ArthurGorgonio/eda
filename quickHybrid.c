#include <stdlib.h>
#include <sys/time.h>
#include "common.h"
#include "insertion.h"
#include "quick.h"
#include "quickHybrid.h"

/*
 * ============================================================================
 *
 *       Filename:  quickHybrid.c
 *
 *    Description:  This file contains the functions to sort a float vector with
 *        Quick sort and insertion sort algorithms.
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
 *           Name:  hybridQuickSort
 *    Description:  This algorithm is hybrid when called we start using Quick
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
void hybridQuickSort(float *v, int i, int f, int threshold) {
  if ((f - i + 1) <= threshold) {
    insertionSort(v, (f - i + 1));
  } else {
    int p;
    if (i < f) {
      exchange(v, (int) ((f + i) / 2), i);
      p = partition (v, i, f);
      hybridQuickSort(v, i, p - 1, threshold);
      hybridQuickSort(v, p + 1, f, threshold);
    }
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  runQuickHybrid
 *    Description:  This function calls the Quick sort and Insertion sort
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
void runQuickHybrid(int length, int nIterations, int maxRange) {
  char *archive = "quickHybrid_10.txt";
  double time = 0.0;
  float *v = (float *) malloc(length * sizeof(float));
  int j;
  struct timeval timeStart, timeStop;
  for (j = 0; j < nIterations; j++) {
    generateValues(v, length, maxRange);
    gettimeofday(&timeStart, NULL);
    hybridQuickSort(v, 0, length, 10);
    gettimeofday(&timeStop, NULL);
    time = computeTime(timeStart, timeStop, time);
  }
  time = time / nIterations;
  writeTime(archive, length, time);
  free(v);
}
