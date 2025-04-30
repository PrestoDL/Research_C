// 2020116706

#include "Queue.h"
#include "Stack.h"

Element menu(char c) {
  switch (c) {
  case '1': {
    return "Ice Cream";
  }
  case '2': {
    return "Bibimbab";
  }
  case '3': {
    return "Bulgogi";
  }
  case '4': {
    return "Coffee";
  }
  case '5': {
    return "Noodle";
  }
  default: {
    exit(0); // errCheck
  }
  }
}

void printStat(Queue *q) {
  int c = CountQueue(q);
  char temp[50];

  printf("\nStat : ");

  for (int i = 0; i < c; i++) {
    strcpy(temp, Dequeue(q));
    printf("%s ", temp);
    Enqueue(q, temp);
  }

  printf("(%d)\n\n\n\n", c);
}

void printServe(Element order) {
  int c = strlen(order);

  Stack *tempStack;
  tempStack = CreateStack(50);

  for (int _ = 0; _ < c; _++) {
    Push(tempStack, menu(order[_]));
  }

  printf("\nServe : ");

  for (int _ = 0; _ < c; _++) {
    if (_ != 0) {
      printf(", ");
    }
    printf("%s", Pop(tempStack));
  }

  printf("\n");
}

int main(void) {
  Queue *queue_order;
  queue_order = CreateQueue(50);

  int sel;
  char order[50];

  while (1) {
    printf("Order (0), Serve (1), Exit (2) : ");
    scanf("%d", &sel);

    switch (sel) {

    case 0: { // order
      printf("\nOrder : ");
      scanf("%s", order);
      int erCheck = 0;

      for (int _ = 0; _ < strlen(order); _++) {
        if (order[_] != '1' && order[_] != '2' && order[_] != '3' &&
            order[_] != '4' &&
            order[_] != '5') { // better idea than this expression?
          printf("\nWrong order input.\n\n\n\n");
          erCheck = 1;
          break;
        }
      }

      if (erCheck == 0) {
        Enqueue(queue_order, order);
        printStat(queue_order);
      }

      break;
    }

    case 1: { // serve
      if (IsEmptyQueue(queue_order) == 1) {
        printf("\nNo order exists.\n\n\n\n");
      }

      else {
        Element tempServe = Dequeue(queue_order);
        printServe(tempServe);
        printStat(queue_order);
      }

      break;
    }

    case 2: { // exit
      exit(0);
      break;
    }

    default: { // errCheck
      printf("\n\nWrong menu input.\n\n");
      break;
    }
    }
  }
  return 0;
}