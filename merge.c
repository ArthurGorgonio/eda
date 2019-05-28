#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "merge.h"

/*
 * ============================================================================
 *
 *       Filename:  merge.c
 *
 *    Description:  This file contains the functions to sort a float vector
 *        with merge sort algorithm.
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
 *           Name:  merge
 *    Description:  Merge two vector in one sorted.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             i => Initial point of the vector.
 *             m => Middle point of the vector.
 *             f => Final point of the vector.
 *
 *         Return:  void
 * ============================================================================
*/
void merge(float *v, int i, int m, int f) {
  float *w = (float *) malloc((f - i + 1) * sizeof(float));
  int a = i, b = m + 1, k;
  for(k = 0; (k <= (f - i)); k++) {
    if((b > f) || ((a <= m) && (v[a] < v[b]))) {
      w[k] = v[a];
      a++;
    } else {
      w[k] = v[b];
      b++;
    }
  }
  for(k = 0; (k <= (f - i)); k++) {
    v[i + k] = w[k];
  }
  free(w);
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  mergeSort
 *    Description:  This algorithm applies the divide-and-conquer paradigm.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             i => Initial point of the vector.
 *             f => Final point of the vector.
 *
 *         Return:  void
 * ============================================================================
*/
void mergeSort(float *v, int i, int f) {
  int m;
  if (i < f) {
    m = (i + f) / 2;
    mergeSort(v, i, m);
    mergeSort(v, m + 1, f);
    merge(v, i, m, f);
  }
}


/*
 * ===  FUNCTION  =============================================================
 *           Name:  runMerge
 *    Description:  This function calls the merge sort algorithm and compute
 *        the time spent.
 *
 *         Params:
 *        length => The length of the vector *v
 *   nIterations => How many times the algorithm run.
 *      maxRange => The range of the numbers.
 *
 *         Return: void
 * ============================================================================
*/
void runMerge(int length, int nIterations, int maxRange) {
  char *archive = "merge.txt";
  double time = 0.0;
  float *v = (float *) malloc(length * sizeof(float));
  int j;
  struct timeval timeStart, timeStop;
  for (j = 0; j < nIterations; j++) {
    generateValues(v, length, maxRange);
    gettimeofday(&timeStart, NULL);
    mergeSort(v, 0, length);
    gettimeofday(&timeStop, NULL);
    time = computeTime(timeStart, timeStop, time);
  }
  time = time / nIterations;
  writeTime(archive, length, time);
  free(v);
}
