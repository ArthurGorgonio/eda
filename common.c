#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "common.h"

/*
 * ============================================================================
 *
 *       Filename:  common.c
 *
 *    Description:  This file contains the common functions for the scripts
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
 *           Name:  computeTime
 *    Description:  Calcule the time in nanoseconds.
 *
 *         Params:
 *         start => Timeval struct.
 *          srop => Timeval struct.
 *          time => The existing time.
 *
 *         Return:  void
 * ============================================================================
*/
double computeTime(struct timeval start, struct timeval stop, double time) {
    time += (((stop.tv_sec - start.tv_sec) * 1000000000)
        + ((stop.tv_usec - start.tv_usec) * 1000));
    return time;
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  exchange
 *    Description:  Swap two elements of the vector.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             i => The index of the element if you want to swap.
 *             j => The index of the element if you want to swap.
 *
 *         Return:  void
 * ============================================================================
*/
void exchange(float *v, int i, int j) {
  float aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  generateValues
 *    Description:  This function generate elements for each position of the
 *        vector.
 *
 *         Params:
 *            *v => An arbitrary vector.
 *             i => The length of the vector.
 *        module => The range of the numbers.
 *
 *         Return:  void
 * ============================================================================
*/
void generateValues(float *v, int n, int module) {
  int i;
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    v[i] = rand() % module;
  }
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  writeTime
 *    Description:  This function open a specific file with append mode and add
 *        the time into this.
 *
 *         Params:
 *         *name => The name of the file to be open.
 *        length => The actual length of the vector.
 *          time => The mean of the some runs of the any sort algorithm.
 *
 *         Return:  void
 * ============================================================================
*/
void writeTime(char *name, int length, double time) {
  FILE *fp;
  fp = fopen(name, "a");
  if (fp != NULL) { 
    fprintf(fp, "%d %.15f\n", length, time);
    fclose(fp);
  } else {
    printf("Something went wrong!");
    exit(0);
  }
}
