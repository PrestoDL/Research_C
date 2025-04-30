#include <stdio.h>
#include <stdlib.h>

void get_in(int **in1, int **in2, int count) {
  *in1 = (int *)malloc(sizeof(int) * count);
  *in2 = (int *)malloc(sizeof(int) * count);

  for (int i = 0; i < count; i++) {
    printf("in1 in2 : ");
    scanf("%d %d", (*in1 + i), (*in2 + i));
  }
}

int *add(int *in1, int *in2, int count) {
  int *result = (int *)malloc(sizeof(int *) * count);

  for (int i = 0; i < count; i++) {
    result[i] = in1[i] + in2[i];
  }
  return result;
}