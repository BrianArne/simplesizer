/* nscale generates frequencies for an N-note octave, from a given MIDI note */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char * argv[]){
  int notes, midinote;
  double frequency, ratio;
  double c0, c5;
  double intervals[24];
  
  if(argc != 3){
    printf("usage: nscale notes midinote\n");
    return 1;
  }
  /* Checks notes arg */
  notes = atoi(argv[1]);
  if (notes < 1){
    printf("ERROR: notes must be positive.\n");
    return 1;
  }
  if (notes > 24){
    printf("ERROR: maximum value for notes is 24.\n");
    return 1;
  }

  /* Checks midinote arg */
  midinote = atoi(argv[2]);
  if (midinote < 0){
    printf("ERROR: cannot have negative MIDI notes.\n");
    return 1;
  }
  if (midinote > 127){
    printf("ERROR: maximum MIDInote is 127.\n");
    return 1;
  }

  ratio = pow(2.0, 1.0 / notes);
  // find Middle C, three semitones above low A == 220
  c5 = 220.0 * pow(ratio, 3.0);
  // MIDI notes 0 is C, 5 octaves below Middle C
  c0 = c5 * pow(.5, 5);
  frequency = c0 * pow(ratio, midinote);

  for(int i = 0; i < notes; i++){
    intervals[i] = frequency;
    frequency *= ratio;
  }

  for(int i = 0; i < notes; i++){
    printf("%f\n", intervals[i]);
  }

  return 0;
}
