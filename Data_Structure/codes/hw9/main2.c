#include "search.h"

int file(Element **ppTemp) {
  char filename[50];
  int i = 0;
  *ppTemp = (Element *)malloc(sizeof(Element) * 1000);

  printf("\nFile name : ");
  scanf("%s", filename);
  getchar();
  FILE *p = fopen(filename, "r");

  if (p != NULL) {
    char line[50];
    while (fgets(line, sizeof(line), p)) {
      (*ppTemp)[i++] = atoi(line);
    }
    fclose(p);
  }

  else {
    printf("There is no file named '%s'. Program terminates.\n\n", filename);
    exit(0);
  }

  return i;
}

int main(void) {
  Element *str;
  file(&str);
  int count = intLen(str);

  printf("Target Integer : ");
  int target;
  scanf("%d", &target);
  getchar();

  printf("\nChoose a searching method (Binary : 0, Hashed : 1) : ");
  int sel;
  scanf("%d", &sel);
  getchar();

  int found;
  switch (sel) {
  case 0: {
    found = binary(str, target);
    break;
  }

  case 1: {
    found = hash(str, target);
    break;
  }

  default: {
    printf("Wrong Input. Program terminates.\n\n");
    exit(0);
  }
  }

  if (found == 1) {
    printf("\n%d is found!\n\n", target);
  }

  else {
    printf("\n%d is not found!\n\n", target);
  }

  return 0;
}