#include "enums.h"
#include <stdio.h>

sign foo(XY coor){
  return coor.x;
}

int main(){
  XY coors;
  coors.x = POSITIVE;

  printf("Coors.x == %d", foo(coors));

  

}

