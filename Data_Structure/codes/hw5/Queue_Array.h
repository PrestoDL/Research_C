// 2020116706

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *Element;
typedef int Boolean;

typedef struct {
  Element (*queue)[50];
  int size;
  int front;
  int rear;
} Queue;

Queue *CreateQueue(int size) {
  Queue *temp = (Queue *)malloc(sizeof(Queue));
  if (temp == NULL) {
    return NULL;
  }

  temp->queue = (Element(*)[50])malloc(size * (sizeof(Element(*)[50]) + 1));
  if (temp->queue == NULL) {
    free(temp);
    return NULL;
  }

  temp->size = size;
  temp->front = 0;
  temp->rear = 0;

  return temp;
}

Boolean IsFullQueue(Queue *temp) {
  if ((temp->rear + 1) % temp->size == temp->front) {
    return 1;
  }

  return 0;
}

Boolean IsEmptyQueue(Queue *temp) {
  if (temp->front == temp->rear) {
    return 1;
  }

  return 0;
}

int CountQueue(Queue *temp) {
  if (temp->rear >= temp->front) {
    return (temp->rear - temp->front);
  }

  else {
    return (temp->rear - temp->front + temp->size);
  }
}

void Enqueue(Queue *temp, Element item) {
  if (IsFullQueue(temp) == 0) {
    temp->rear = (temp->rear + 1) % (temp->size + 1);
  }

  strcpy(temp->queue[temp->rear], item);
}

Element Dequeue(Queue *temp) {
  if (IsEmptyQueue(temp) == 0) {
    Element item = temp->queue[(temp->front + 1) % (temp->size + 1)];
    temp->front = (temp->front + 1) % (temp->size + 1);

    return item;
  }
}

Element QueueFront(Queue *temp) {
  if (IsEmptyQueue(temp) == 0) {
    return temp->queue[(temp->front + 1) % (temp->size + 1)];
  }
}

Element QueueRear(Queue *temp) {
  if (IsEmptyQueue(temp) == 0) {
    return temp->queue[temp->rear];
  }
}

void DestroyQueue(Queue *temp) {
  if (temp == NULL) {
    return;
  }

  else {
    free(temp->queue);
    free(temp);
  }
}