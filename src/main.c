#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void run_cmd(char **cmd) {
  pid_t pid = fork();
  if (pid == 0) {
    // child
    execvp(cmd[0], cmd);
  } else {
    return;
  }
}

double expinv(double x, double rate) {
  return (-log(1.0 - x)) / rate;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("pp: execute command according to a poisson process\n\nusage: pp [RATE] [COMMAND]\nnote: rate is per minute\n");
    return 1;
  }
  double rate = atof(argv[1]);
  char **cmd = argv + 2;

  while(true) {
    double x = (double)rand() / (double)RAND_MAX;
    double wait_min = expinv(x, rate);

    usleep((long)(wait_min * 60000000));

    run_cmd(cmd);
  }
  return 0;
}
