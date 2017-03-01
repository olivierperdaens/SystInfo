#include <stdio.h>
#include <stdlib.h>


#define SIZE 10000

int matrix[SIZE][SIZE];

int sum() {
  int sum=0;
  size_t i,j;
  for(i=0;i<SIZE;i++) {
    for(j=0;j<SIZE;j++) {
      sum+=matrix[i][j];
    }
  }
  return sum;
}

int sum2() {
  int sum=0;
  size_t i,j;
  for(i=0;i<SIZE;i++) {
    for(j=0;j<SIZE;j++) {
      sum+=matrix[j][i];
    }
  }
  return sum;
}

int main(void){
  struct timeval tvalBefore1, tvalAfter1, tvalBefore2, tvalAfter2;
  gettimeofday(&tvalBefore1, NULL);
  int a=sum();
  gettimeofday(&tvalAfter1, NULL);
  int b=sum2();
  gettimeofday(&tvalAfter2, NULL);
  printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter1.tv_sec - tvalBefore1.tv_sec)*1000000L
           +tvalAfter1.tv_usec) - tvalBefore1.tv_usec
          );
  printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter2.tv_sec - tvalAfter1.tv_sec)*1000000L
           +tvalAfter2.tv_usec) - tvalAfter1.tv_usec
          );
 
  return EXIT_SUCCESS;
}
