#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double expinv(double x, double rate) {
  return (-log(1.0 - x)) / rate;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("usage: pp <rate> <string>\nnote: rate is per minute\n");
    return 1;
  }
  double rate = atof(argv[1]);
  char *s = argv[2];

  while(true) {
    double x = (double)rand() / (double)RAND_MAX;
    double wait_min = expinv(x, rate);

    usleep((long)(wait_min * 60000000));

    printf("%s\n", s);
  }
  return 0;
}
