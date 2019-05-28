#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
double computeTime(struct timeval start, struct timeval stop, double time) {
    time += (((stop.tv_sec - start.tv_sec) * 1000000000)
        + ((stop.tv_usec - start.tv_usec) * 1000));
    return time;
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

void generateValues(float *v, int n, int module) {
  int i;
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    v[i] = rand() % module;
  }
}

void writeTime(char *name, int length, double time) {
  FILE *fp;
  fp = fopen(name, "a");
  if (fp != NULL) { 
    fprintf(fp, "%d %.15lf\n", length, time);
    fclose(fp);
  } else {
    printf("Something went wrong!");
    exit(0);
  }
}
