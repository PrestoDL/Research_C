// 2020116706

#include "Ad_Matrix3.h"

char file(Graph **ppTemp) {
  char filename[50];
  char first;
  printf("\nFile name : ");
  scanf("%s", filename);
  FILE *p = fopen(filename, "r");
  if (p != NULL) {
    char line[50];
    fgets(line, sizeof(line), p);
    first = *line;

    char *c1, *c2;
    int w;
    while (fgets(line, sizeof(line), p)) {
      c1 = strtok(line, " ");
      c2 = strtok(NULL, " ");
      w = atoi(strtok(NULL, " "));

      if ((c1 == NULL) || (c2 == NULL) || (w == 0)) {
        printf("Invalid Input. Program terminates.\n\n");
        exit(0);
      }

      AddEdge(*ppTemp, *c1, *c2, w);
    }
    fclose(p);
  }

  else {
    printf("There is no file named '%s'. Program terminates.\n\n", filename);
    exit(0);
  }
  return first;
}

int main(void) {
  Graph *pG;
  pG = CreateGraph(50);

  char start = file(&pG);

  PrintGraph(pG);
  printf("\n\n\n");

  MinSpanningTree(pG, start);
  printf("\n\n\n");

  ShortestPath(pG, start);
  printf("\n\n\n");

  DestroyGraph(pG);

  return 0;
}