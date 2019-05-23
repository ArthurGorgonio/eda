#include <stdlib.h>
#include "sort.h"
#include "utils.h"

/*
 * ============================================================================
 *
 *       Filename:  sort.c
 *
 *    Description:  This file contains some sort function to sort an arbitrary
 *        vector, independent of the length.
 *
 *        Version:  1.1
 *        Created:  2019 Mar 01 20:08
 *    Last Edited:  2019 May 27 17:00
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
 *           Name:  bubble_sort
 *    Description:  This function implements the bubble method for sort all
 *        elements of the vector, comparing two elements and swapping when
 *        necessary.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of vector *v.
 *
 *         Return:  void
 * ============================================================================
*/
void bubble_sort(int *v, int n) {
  int aux, i, j;
  for(i = 0; i < (n - 1); i++) {
    for(j = (n - 1); j > i; j--) {
      if (v[j] < v[j - 1]) {
        aux = v[j - 1];
        v[j - 1] = v[j];
        v[j] = aux;
      }
    }
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  counting_sort
 *    Description:  This function implements the counting method for sort all
 *        elements of the vector. It works creating another vector to count the
 *        position of the element in output vector.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of vector *v.
 *
 *         Return:  void
 * ============================================================================
*/
void counting_sort(int *v, int n) {
  int *w;
  int c, i, j;
  w = malloc(n * sizeof(int));
  clear_vector(w, n);
  for(i = 0; i < n; i++) {
    c = 0;
    for(j = 0; j < n; j++) {
      if(v[i] > v[j]) {
        c++;
      }
    }
    w[c + 1] = v[i];
  }
  for(i = 0; i < n; i++) {
    v[i] = w[i];
  }
  free(w);
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  distribution_sort
 *    Description:  Create a auxiliar vector with the range of the elements.
 *        And count the times of the each element repeat.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *            *w => An arbitrary vector.
 *             n => The length of vector *v.
 *           min => The smallest element of vector *v.
 *           max => The higgest element of vector *v.
 *
 *         Return:  void
 * ============================================================================
*/
void distribution_sort(int *v, int *w, int n, int min, int m) {
  int a = 0, i;
  for(i = 0; i < n; i++) {
    w[v[i] - min] = w[v[i] - min] + 1;
  }
  for(i = 0; i < n; i++) {
    while(w[i] > 0) {
      v[a] = i + min;
      a++;
      w[i]--;
    }
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  insertion_sort
 *    Description:  Order a vector in the same vector, order in-place.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of vector *v.
 *
 *         Return:  void
 * ============================================================================
*/
void insertion_sort(int *v, int n) {
  int a, i, f;
  for(i = 1; i < n; i++) {
    a = i - 1;
    while ((a >= 0) && (v[a] > v[a + 1])) {
      f = v[a];
      v[a] = v[a + 1];
      v[a + 1] = f;
      a--;
    }
  }
}

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
void merge(int *v, int i, int m, int f) {
  int *w = (int *) malloc((f - i + 1) * sizeof(int));
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
 *           Name:  merge_sort
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
void merge_sort(int *v, int i, int f) {
  int m;
  if (i < f) {
    m = (i + f) / 2;
    merge_sort(v, i, m);
    merge_sort(v, m + 1, f);
    merge(v, i, m, f);
  }
}

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
int partition(int *v, int i, int f) {
  int b = i + 1, k, p = i;
  double l;
  for(k = i + 1; k <= f; k++) {
    if (v[p] > v[k]) {
      l = v[k];
      v[k] = v[b];
      v[b] = l;
      b++;
    }
  }
  l = v[b - 1];
  v[b - 1] = v[p];
  v[p] = l;
  return (b - 1);
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  quick_sort
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
void quick_sort(int *v, int i, int f) {
  int a, p;
  if (i < f) {
    a = v[i];
    v[i] = v[(int)(f + i) / 2];
    v[(f + i) / 2] = a;
    p = partition (v, i, f);
    quick_sort(v, i, p - 1);
    quick_sort(v, p + 1, f);
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  parent
 *    Description:  This function implements the method to find the parent in
 *        heap sort algorithm.
 *
 *         Params:
 *             i => The index of the element if you want to know your parent.
 *
 *         Return:
 *            Int: The index of the parent of the element.
 * ============================================================================
*/
int parent(int i) {
  return ((int) (i + 1) / 2);
}

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
 *           Name:  max_heapify
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
void max_heapify(int *v, int n, int i) {
  int l, largest, r, aux;
  l = left(i);
  r = right(i);
  if ((l <= (n - 1)) && (v[l] > v[i])) {
    largest = l;
  } else {
    largest = i;
  }
  if ((r <= (n - 1)) && (v[r] > v[largest])) {
    largest = r;
  }
  if (largest != i) {
    aux = v[i];
    v[i] = v[largest];
    v[largest] = aux;
    max_heapify(v, n, largest);
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  build_max_heap
 *    Description:  Auxiliar function to heapsort algorithm, this build a max
 *        heap.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of the vector *v.
 *
 *         Return: void
 * ============================================================================
*/
void build_max_heap(int *v, int n) {
  int i;
  for (i = (int) ((n - 1) / 2); i >= 0; i--) {
    max_heapify(v, n, i);
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  heapsort
 *    Description:  The heapsort algorithm only the core.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of the vector *v.
 *
 *         Return: void
 * ============================================================================
*/
void heapsort(int *v, int n) {
  int i, aux;
  build_max_heap(v, n);
  for (i = (n - 1); i >= 1; i--) {
    n--;
    aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    max_heapify(v, n, 0);
  }
}
