#include <stdio.h>
#include <stdlib.h>
#include "fractions.h"

int fraction_compare(const void * a, const void * b){
  fraction_t* frac1=(fraction_t*) a;
  fraction_t* frac2=(fraction_t*) b;
  float resultf1 = ((float) a->numerateur) / ((float) a->denominateur);
  float resultf2 = ((float) b->numerateur) / ((float) b->denominateur);
  if(resultf1 > resultf2){
    return 1;
  }
  else if(resultf1 < resultf2){
    return -1;
  }
  return 0;
}
