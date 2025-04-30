// 2020116706

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Element;
typedef int Boolean;

typedef struct tQueueNode {
  struct tQueueNode *nextNode;
  Element data;
} QueueNode;

typedef struct {
  QueueNode *front;
  QueueNode *rear;
  int count;
} Queue;

Queue *CreateQueue() {
  Queue *temp;
  temp = (Queue *)malloc(sizeof(Queue));

  if (temp == NULL) {
    return;
  }

  temp->count = 0;
  return temp;
}

Boolean IsEmptyQueue(Queue *temp) {
  if (temp->count == 0) {
    return 1;
  }

  else {
    return 0;
  }
}

int CountQueue(Queue *temp) {
  if (IsEmptyQueue(temp) == 1) {
    return;
  }

  else {
    return temp->count;
  }
}

void Enqueue(Queue *temp, Element item) {
  if (temp == NULL) {
    return;
  }

  else {
    QueueNode *tempNode;
    tempNode = (QueueNode *)malloc(sizeof(QueueNode));
    tempNode->data = item;

    if (temp->count == 0) {
      temp->front = tempNode;
      temp->rear = tempNode;
    }

    else {
      temp->rear->nextNode = tempNode;
      temp->rear = tempNode;
    }

    temp->count++;
  }
}

Element Dequeue(Queue *temp) {
  if (temp == NULL || IsEmptyQueue(temp) == 1) {
    return;
  }

  else {
    Element item;

    if (temp->count == 1) {
      item = temp->front->data;
      free(temp->front);
    }

    else {
      QueueNode *recycle;
      recycle = temp->front;
      item = recycle->data;
      temp->front = temp->front->nextNode;
      free(recycle);
    }

    temp->count--;
    return item;
  }
}

Element QueueFront(Queue *temp) {
  if (IsEmptyQueue(temp) == 1) {
    return;
  }

  else {
    return temp->front->data;
  }
}

Element QueueRear(Queue *temp) {
  if (IsEmptyQueue(temp) == 1) {
    return;
  }

  else {
    return temp->rear->data;
  }
}

void DestroyQueue(Queue *temp) {
  if (temp == NULL) {
    return;
  }

  else {
    free(temp);
  }
}