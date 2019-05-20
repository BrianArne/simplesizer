#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum {ARG_PROGNAME, ARG_AMP, ARG_NARGS};

int main(int argc, char** argv){
  float amp;
  float decibel;

  if (argc != ARG_NARGS){
    printf("Error\n" 
           "\tusage: amp2deci amp\n") ;
    return 1;
  }

  amp = atof(argv[ARG_AMP]);
  if(amp < 0){
    printf("Error: Amplitude must be >= zero\n");
    return 1;
  }

  decibel = 20 * log10(amp);
  printf("Amplitude of %f is %f decibels\n", amp, decibel);

  return 0;
}
