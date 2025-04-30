// 2020116706

#include "List_Link.h"
#include "Queue_Link.h"
#include "Stack_Link.h"

typedef List Graph;
typedef List Vertex;

int _AddVertex(Graph *pTemp, char a) {
  AddNode(pTemp, a);

  ListNode *pL = FindNode(pTemp, a);
  if (pL->first == NULL) {
    Vertex *pV = CreateList();
    pL->first = pV;
  }

  return pTemp->count;
}

void AddEdge(Graph *pTemp, char c1, char c2) {
  if (SearchNode(pTemp, c1) == 0) {
    _AddVertex(pTemp, c1);
  }

  if (SearchNode(pTemp, c2) == 0) {
    _AddVertex(pTemp, c2);
  }

  ListNode *pL = FindNode(pTemp, c1);
  AddNode((pL->first), c2);
}

void RemoveEdge(Graph *pTemp, char c1, char c2) {
  ListNode *pG = FindNode(pTemp, c1);
  if (pG == NULL) {
    return; // 존재하지 않는 Vertex의 Edge는 무시
  }

  RemoveNode(pG->first, c2);
}

void RemoveVertex(Graph *pTemp, char a) {
  ListNode *pG = FindNode(pTemp, a);
  if (pG == NULL) {
    return; // 존재하지 않는 Vertex는 무시
  }
  DestroyList(pG->first);
  RemoveNode(pTemp, a);

  ListNode *pPre = NULL, *pPos = NULL;
  for (pPre = pTemp->head; pPre != NULL; pPre = pPos) {
    pPos = pPre->next;
    RemoveNode(pPre->first, a);
  }
}

Graph *CreateGraph() {
  Graph *pTemp = (Graph *)malloc(sizeof(Graph));

  pTemp->head = NULL;
  pTemp->count = 0;

  return pTemp;
}

void PrintGraph(Graph *pTemp) {
  ListNode *pPre1 = NULL, *pPos1 = NULL;
  ListNode *pPre2 = NULL, *pPos2 = NULL;

  for (pPre1 = pTemp->head; pPre1 != NULL; pPre1 = pPos1) {
    pPos1 = pPre1->next;
    printf("\n\n%c : ", pPre1->data);

    for (pPre2 = pPre1->first->head; pPre2 != NULL; pPre2 = pPos2) {
      pPos2 = pPre2->next;
      printf("%c ", pPre2->data);
    }
  }
}

void DestroyGraph(Graph *pTemp) {
  ListNode *pPre = NULL, *pPos = NULL;

  for (pPre = pTemp->head; pPre != NULL; pPre = pPos) {
    pPos = pPre->next;
    DestroyList(pPre->first);
  }
  DestroyList(pTemp);
}

void DepthFirst(Graph *pTemp, char start) {
  List *check;
  check = CreateList();

  Stack *pS;
  pS = CreateStack();

  char now;
  Push(pS, start);
  AddNode(check, start);

  printf("Depth First Traversal : ");

  ListNode *pPre = NULL, *pPos = NULL;
  while (IsEmptyStack(pS) != 1) {
    now = Pop(pS);
    printf("%c ", now);

    for (pPre = FindNode(pTemp, now)->first->head; pPre != NULL; pPre = pPos) {
      pPos = pPre->next;

      if (SearchNode(check, pPre->data) == 0) {
        Push(pS, pPre->data);
        AddNode(check, pPre->data);
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

  char now;
  Enqueue(pQ, start);
  AddNode(check, start);

  printf("Breadth First Traversal : ");

  ListNode *pPre = NULL, *pPos = NULL;
  while (IsEmptyQueue(pQ) != 1) {
    now = Dequeue(pQ);
    printf("%c ", now);

    for (pPre = FindNode(pTemp, now)->first->head; pPre != NULL; pPre = pPos) {
      pPos = pPre->next;

      if (SearchNode(check, pPre->data) == 0) {
        Enqueue(pQ, pPre->data);
        AddNode(check, pPre->data);
      }
    }
  }
  DestroyList(check);
  DestroyQueue(pQ);
}