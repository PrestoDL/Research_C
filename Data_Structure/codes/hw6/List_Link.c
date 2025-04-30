#include "List_Link.h"

void currentList(List *pTemp) {
  if (IsEmptyList(pTemp) == 1) {
    printf("\nThe List is Empty.\n\n\n\n");
    return;
  }

  printf("\nThe current status of List : ");
  ShowList(pTemp);
  printf("\n\n\n\n");
}

int main(void) {
  List *MainList;
  MainList = CreateList();

  int sel;
  while (1) {
    printf("In (0), Search (1), Out (2), Exit (3) : ");
    scanf("%d", &sel);
    getchar();

    switch (sel) {
    case 0: {
      Element n;
      printf("\nIn : ");
      scanf("%d", &n);
      getchar();

      AddNode(MainList, n);
      currentList(MainList);
      break;
    }

    case 1: {
      if (IsEmptyList(MainList) == 1) {
        printf("\nThe List is Empty.\n\n\n\n");
      }

      else {
        Element n;
        printf("\nSearch : ");
        scanf("%d", &n);
        getchar();

        if (SearchNode(MainList, n) == 1) {
          printf("\nMy List has %d.\n", n);
        }

        else {
          printf("\nMy List does NOT have %d.\n", n);
        }

        currentList(MainList);
      }

      break;
    }

    case 2: {
      if (IsEmptyList(MainList) == 1) {
        printf("\nThe List is Empty.\n\n\n\n");
      }

      else {
        Element n;
        printf("\nOut : ");
        scanf("%d", &n);
        getchar();

        RemoveNode(MainList, n);
        currentList(MainList);
      }

      break;
    }

    case 3: {
      DestroyList(MainList);
      exit(0);
    }

    default: {
      printf("\nWrong Input.\n\n\n\n");
      break;
    }
    } // end of switch
  }
}