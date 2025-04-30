// 2020116706

#include "List_Link.h"
#include "Queue_Link.h"
#include "Stack_Link.h"

typedef int Boolean;

typedef struct tGraph {
  char *List;
  int **Matrix;
  int count;
  int max;
} Graph;

int **_CreateMatrix(int n) {
  int **ppTemp;
  ppTemp = (int **)malloc(sizeof(int *) * n);

  for (int i = 0; i < n; i++) {
    ppTemp[i] = (int *)malloc(sizeof(int) * n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ppTemp[i][j] = 0;
    }
  }

  return ppTemp;
}

char *_CreateList(int n) {
  char *pList;
  pList = (char *)malloc(sizeof(char) * n);

  return pList;
}

int _FindVertex(Graph *pTemp, char a) {
  int i;
  int c = pTemp->count;

  for (i = 0; i < c; i++) {
    if (pTemp->List[i] == a) {
      return i;
    }
  }
  return -i - 1; // can't find
}

int _SetVertex(Graph *pTemp, char a) {
  int i = _FindVertex(pTemp, a);
  if (i < 0) // new vertex
  {
    i = -i - 1;
    pTemp->List[i] = a;
    pTemp->count++;
  }

  return i;
}

Graph *CreateGraph(int n) {
  Graph *pTemp;
  pTemp = (Graph *)malloc(sizeof(Graph));

  pTemp->Matrix = _CreateMatrix(n);
  pTemp->List = _CreateList(n);
  pTemp->count = 0;
  pTemp->max = n;

  return pTemp;
}

void AddEdge(Graph *pTemp, char c1, char c2) {
  int i1 = _SetVertex(pTemp, c1);
  int i2 = _SetVertex(pTemp, c2);

  pTemp->Matrix[i1][i2] = 1;
}

void RemoveEdge(Graph *pTemp, char c1, char c2) {
  if ((_FindVertex(pTemp, c1) < 0) || (_FindVertex(pTemp, c2) < 0)) {
    return; // 존재하지 않는 vertex에 대한 edge의 경우 무시
  }

  int i1 = _SetVertex(pTemp, c1);
  int i2 = _SetVertex(pTemp, c2);

  pTemp->Matrix[i1][i2] = 0;
}

void PrintGraph(Graph *pTemp) {
  int c = pTemp->count;

  for (int i = 0; i < c; i++) {
    printf("\n\n%c : ", pTemp->List[i]);
    for (int j = 0; j < c; j++) {
      if (pTemp->Matrix[i][j] == 1) {
        printf("%c ", pTemp->List[j]);
      }
    }
  }
}

void DestroyGraph(Graph *pTemp) {
  int c = pTemp->max;

  for (int i = 0; i < c; i++) {
    free(*(pTemp->Matrix + i));
  }
  free(pTemp->Matrix);
  free(pTemp->List);
  free(pTemp);
}

void DepthFirst(Graph *pTemp, char start) {
  List *check;
  check = CreateList();

  Stack *pS;
  pS = CreateStack();

  int c = pTemp->count;
  int now;
  Push(pS, _FindVertex(pTemp, start));
  AddNode(check, _FindVertex(pTemp, start));

  printf("Depth First Traversal : ");

  while (IsEmptyStack(pS) != 1) {
    now = Pop(pS);
    printf("%c ", pTemp->List[now]);

    for (int i = 0; i < c; i++) {
      if ((pTemp->Matrix[now][i] == 1) && (SearchNode(check, i) != 1)) {
        Push(pS, i);
        AddNode(check, i);
      }
    }
  }
  DestroyList(check);
  DestroyStack(pS);
}

void BreathFirst(Graph *pTemp, char start) {
  List *check;
  check = CreateList();

  Queue *pQ;
  pQ = CreateQueue();

  int c = pTemp->count;
  int now;
  Enqueue(pQ, _FindVertex(pTemp, start));
  AddNode(check, _FindVertex(pTemp, start));

  printf("Breath First Traversal : ");

  while (IsEmptyQueue(pQ) != 1) {
    now = Dequeue(pQ);
    printf("%c ", pTemp->List[now]);

    for (int i = 0; i < c; i++) {
      if ((pTemp->Matrix[now][i] == 1) && (SearchNode(check, i) != 1)) {
        Enqueue(pQ, i);
        AddNode(check, i);
      }
    }
  }
  DestroyList(check);
  DestroyQueue(pQ);
}