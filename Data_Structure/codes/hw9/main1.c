#include "sort.h"

int file(Element **ppTemp) {
  char filename[50];
  int i = 0;
  *ppTemp = (Element *)malloc(sizeof(Element) * 1000);

  printf("\nFile name : ");
  scanf("%s", filename);
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

  printf("Choose a sorting method to use (Selection : 0, Insertion : 1, Bubble "
         ": 2, Quick : 3, Merge : 4 ) : ");
  int sel;
  scanf("%d", &sel);
  switch (sel) {
  case 0: {
    selection(&str);
    break;
  }

  case 1: {
    insertion(&str);
    break;
  }

  case 2: {
    bubble(&str);
    break;
  }

  case 3: {
    quick(&str);
    break;
  }

  case 4: {
    merge(&str);
    break;
  }

  default: {
    printf("Wrong Input. Program terminates.\n\n");
    exit(0);
  }
  }

  printf("\n\nThe numbers sorted : ");
  printArray(str);
  printf("\nDone!");

  return 0;
}