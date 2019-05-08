// Write sinewave as text

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.141592654)
#endif

enum {ARG_NAME, ARG_NSAMPS, ARG_FREQ, ARG_SR, ARG_NARGS};

int main(int argc, char** argv){
  int j;
  int i, nsamps;
  double samp, freq, srate;
  double twopi = 2.0 * M_PI;
  double angleincr;

  if(argc != ARG_NARGS){
    fprintf(stderr, "usage: sinetext nsamps freq srate\n");
    return 1;
  }
  nsamps = atoi(argv[ARG_NSAMPS]);
  freq = atoi(argv[ARG_FREQ]);
  srate = atoi(argv[ARG_SR]);

  // Make one complete cycle
  angleincr = twopi * freq/srate;
  while (j < 1000 ){
    for (i = 0; i < nsamps; i++){
      samp = sin(angleincr * i);
      fprintf(stdout, "%.8lf\t%.8lf\n", samp, samp*samp);
    }
    j++;
  }
  fprintf(stderr, "done\n");
  return 0;
}
