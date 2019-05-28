#include <stdlib.h>
#include <sys/time.h>
#include "common.h"
#include "heap.h"

/*
 * ============================================================================
 *
 *       Filename:  heap.c
 *
 *    Description:  This file contains the functions to sort a float vector
 *        with heap sort algorithm.
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
 *           Name:  left
 *    Description:  Find the left children of the element.
 *
 *         Params:
 *             i => The index of the element if you want to know your left
 *        children.
 *
 *         Return:
 *            Int: The index of the left children.
 * ============================================================================
*/
int left(int i) {
  return (2 * i + 1);
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  right
 *    Description:  Find the right children of the element.
 *
 *         Params:
 *             i => The index of the element if you want to know your right
 *        children.
 *
 *         Return:
 *            Int: The index of the right children.
 * ============================================================================
*/
int right(int i) {
  return (2 * i + 2);
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  maxHeapify
 *    Description:  This function maintain the max-heap property, the parent >
 *    your children.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of the vector *v.
 *             i => The element would be adjusted.
 *
 *         Return: void
 * ============================================================================
*/
void maxHeapify(float *v, int n, int i) {
  int l, largest, r;
  l = left(i);
  r = right(i);
  if ((l < n) && (v[l] > v[i])) {
    largest = l;
  } else {
    largest = i;
  }
  if ((r < n) && (v[r] > v[largest])) {
    largest = r;
  }
  if (largest != i) {
    exchange(v, i, largest);
    maxHeapify(v, n, largest);
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  buildMaxHeap
 *    Description:  Auxiliar function to heapSort algorithm, this build a max
 *        heap.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of the vector *v.
 *
 *         Return: void
 * ============================================================================
*/
void buildMaxHeap(float *v, int n) {
  int i;
  for (i = (int) ((n / 2) - 1); i >= 0; i--) {
    maxHeapify(v, n, i);
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  heapSort
 *    Description:  The heapSort algorithm only the core.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of the vector *v.
 *
 *         Return: void
 * ============================================================================
*/
void heapSort(float *v, int n) {
  int i;
  buildMaxHeap(v, n);
  for (i = (n - 1); i > 0; i--) {
    exchange(v, 0, i);
    maxHeapify(v, --n, 0);
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  runHeap
 *    Description:  This function calls the heap sort algorithm and compute the
 *        time spent.
 *
 *         Params:
 *        length => The length of the vector *v
 *   nIterations => How many times the algorithm run.
 *      maxRange => The range of the numbers.
 *
 *         Return: void
 * ============================================================================
*/
void runHeap(int length, int nIterations, int maxRange) {
  char *archive = "heap.txt";
  double time = 0.0;
  float *v = (float *) malloc(length * sizeof(float));
  int j;
  struct timeval timeStart, timeStop;
  for (j = 0; j < nIterations; j++) {
    generateValues(v, length, maxRange);
    gettimeofday(&timeStart, NULL);
    heapSort(v, length);
    gettimeofday(&timeStop, NULL);
    time = computeTime(timeStart, timeStop, time);
  }
  time = time / nIterations;
  writeTime(archive, length, time);
  free(v);
}
