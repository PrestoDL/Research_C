// 2020116706

#include "Queue_Array.h" // Array 큐의 경우 include
//#include "Queue_Link.h" // Link 큐의 경우 include

void current(Queue *bank) {
  Element temp[50];
  printf("The current status of Queue : (");
  for (int count = 0; count < CountQueue(bank); count++) {
    if (count != 0) {
      printf(", ");
    }
    strcpy(temp, Dequeue(bank));
    printf("%s%d", temp, count + 1);
    Enqueue(bank, temp);
  }
  printf(")\n\n\n");
}

int main(void) {
  Queue *bank;
  bank = CreateQueue(100);

  int sel;
  Element name[50];

  while (1) {
    printf("In (0), out (1), exit (2) : ");
    scanf("%d", &sel);

    switch (sel) {
    case 0: {
      printf("\nCustomer : ");
      scanf("%s", name);

      Enqueue(bank, name);
      current(bank);
      break;
    }
    case 1: {
      if (IsEmptyQueue(bank) == 0) {
        printf("\nCustomer Dequeued : %s\n", Dequeue(bank));
        current(bank);
      } else {
        printf("\nQueue is empty.\n\n");
      }

      break;
    }
    case 2: {
      DestroyQueue(bank);
      exit(0);
    }
    default: {
      printf("\nwrong input.\n\n");
      break;
    }
    }
  }
  return 0;
}