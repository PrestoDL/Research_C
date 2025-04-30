// 2020116706

#include "Ad_List.h" // Ad_List 활용 시 include
// #include "Ad_Matrix.h" // Ad_Matrix 활용 시 include

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
    while (fgets(line, sizeof(line), p)) {
      c1 = strtok(line, " ");
      c2 = strtok(NULL, " ");

      if ((c1 == NULL) || (c2 == NULL)) {
        printf("Invalid Input. Program terminates.\n\n");
        exit(0);
      }

      AddEdge(*ppTemp, *c1, *c2);
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

  printf("\n\n");
  DepthFirst(pG, start);

  printf("\n\n");
  BreathFirst(pG, start);

  DestroyGraph(pG);

  return 0;
}