#include <stdio.h>
#include <math.h>

int main(){
  
  double semitone_ratio;
  double c0;  // for frequency of MIDI Note 0
  double c5;  // for frequency of Middle C
  double frequency; // desired hz
  int midinote;  // given this note

  // Calculate required numbers

  semitone_ratio = pow(2, 1./12.0);
  //Find middle C, three semitones above low A == 220
  c5 = 220. * pow(semitone_ratio, 3);
  // MIDI Note - is C, 5 octaves below Middle C
  c0 = c5 * pow(.5 , 5);

  midinote = 70;
  frequency = c0 * pow(semitone_ratio, midinote);

  printf("MIDI note %d has frequency %f\n", midinote, frequency);

  return 0;

}
