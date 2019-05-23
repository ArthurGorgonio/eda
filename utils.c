#include "utils.h"

/*
 * ============================================================================
 *
 *       Filename:  utils.c
 *
 *    Description:  This file contains useful functions to be applied in
 *        arbitrary vectors, independent of the length.
 *
 *        Version:  1.0
 *        Created:  2019 Mar 03 17:00
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
 *           Name:  clear_vector
 *    Description:  For each position of the vector put 0.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of vector *v.
 *
 *         Return:  void
 * ============================================================================
*/
void clear_vector(int *v, int n) {
  int i;
  for(i = 0; i < n; i++) {
    v[i] = 0;
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  maximus
 *    Description:  Find the highest element of the vector.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of vector *v.
 *
 *         Return:  The value of the highest vector element.
 * ============================================================================
*/
int maximus(int *v, int n) {
  int i, max = v[0];
  for(i = 1; i < n; i++) {
    if(max < v[i]) {
      max = v[i];
    }
  }
  return max;
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  minimus
 *    Description:  Find the smallest element of the vector.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             n => The length of vector *v.
 *
 *         Return:  The value of the smallest vector element.
 * ============================================================================
*/
int minimus(int *v, int n) {
  int i, min = v[0];
  for(i = 1; i < n; i++) {
    if(min > v[i]) {
      min = v[i];
    }
  }
  return min;
}

