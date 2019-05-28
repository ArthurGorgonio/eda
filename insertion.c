#include <stdlib.h>
#include <sys/time.h>
#include "common.h"
#include "insertion.h"

/*
 * ============================================================================
 *
 *       Filename:  insertion.c
 *
 *    Description:  This file contains the functions to sort a float vector
 *        with insertion sort algorithm.
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
 *           Name:  insertionSort
 *    Description:  Order a vector in the same vector, order in-place.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of vector *v.
 *
 *         Return:  void
 * ============================================================================
*/
void insertionSort(float *v, int n) {
  float key;
  int i, j;
  for(j = 1; j < n; j++) {
    key = v[j];
    i = j - 1;
    while ((i >= 0) && (v[i] > key)) {
      v[i + 1] = v[i];
      i--;
    }
    v[i + 1] = key;
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  runInsertion
 *    Description:  This function calls the insertion sort algorithm and
 *        compute the time spent.
 *
 *         Params:
 *        length => The length of the vector *v
 *   nIterations => How many times the algorithm run.
 *      maxRange => The range of the numbers.
 *
 *         Return: void
 * ============================================================================
*/
void runInsertion(int length, int nIterations, int maxRange) {
  char *archive = "insertion.txt";
  double time = 0.0;
  float *v = (float *) malloc(length * sizeof(float));
  int j;
  struct timeval timeStart, timeStop;
  for (j = 0; j < nIterations; j++) {
    generateValues(v, length, maxRange);
    gettimeofday(&timeStart, NULL);
    insertionSort(v, length);
    gettimeofday(&timeStop, NULL);
    time = computeTime(timeStart, timeStop, time);
  }
  time = time / nIterations;
  writeTime(archive, length, time);
  free(v);
}
