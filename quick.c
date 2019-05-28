#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "quick.h"

/*
 * ============================================================================
 *
 *       Filename:  quick.c
 *
 *    Description:  This file contains the functions to sort a float vector with
 *        quick sort algorithm.
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
 *           Name:  partition
 *    Description:  This is a function to split the vector in two.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             i => Initial point of the vector.
 *             f => Final point of the vector.
 *
 *         Return:  An integer representing the position of the vector that
 *         will be splited.
 * ============================================================================
*/
int partition(float *v, int i, int f) {
  int b = i + 1, k, p = i;
  for(k = b; k <= f; k++) {
    if (v[p] > v[k]) {
      exchange(v, b, k);
      b++;
    }
  }
  exchange(v, b - 1, p);
  return (b - 1);
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  quickSort
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
void quickSort(float *v, int i, int f) {
  int p;
  if (i < f) {
    exchange(v, (int) ((f + i) / 2), i);
    p = partition (v, i, f);
    quickSort(v, i, p - 1);
    quickSort(v, p + 1, f);
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  runQuick
 *    Description:  This function calls the quick sort algorithm and compute
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
void runQuick(int length, int nIterations, int maxRange) {
  char *archive = "quick.txt";
  double time = 0.0;
  float *v = (float *) malloc(length * sizeof(float));
  int j;
  struct timeval timeStart, timeStop;
  for (j = 0; j < nIterations; j++) {
    generateValues(v, length, maxRange);
    gettimeofday(&timeStart, NULL);
    quickSort(v, 0, length);
    gettimeofday(&timeStop, NULL);
    time = computeTime(timeStart, timeStop, time);
  }
  time = time / nIterations;
  writeTime(archive, length, time);
  free(v);
}
