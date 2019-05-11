// Write sinewave as text

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.141592654)
#endif

enum {ARG_NAME, ARG_DUR, ARG_FREQ, ARG_SR, ARG_NARGS};

int main(int argc, char** argv){
  int i, nsamps, dur;
  double samp, freq, srate;
  double twopi = 2.0 * M_PI;
  double angleincr;

  if(argc != ARG_NARGS){
    fprintf(stderr, "usage: sinetext dur freq srate\n");
    return 1;
  }
  dur = atoi(argv[ARG_DUR]);
  freq = atoi(argv[ARG_FREQ]);
  srate = atoi(argv[ARG_SR]);
  nsamps = (int) (dur * srate);

  // Make one complete cycle
  angleincr = twopi*(freq/srate);
  for (i = 0; i < nsamps; i++){
    samp = sin(angleincr * i);
    fprintf(stdout, "%.8lf\n", samp);
  }
  fprintf(stderr, "done\n");
  return 0;
}
