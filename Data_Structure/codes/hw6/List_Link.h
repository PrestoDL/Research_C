#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef int Boolean;

typedef struct tListNode {
  Element data;
  struct tListNode *next;
} ListNode;

typedef struct {
  int count;
  ListNode *head;
} List;

int _listCount(List *pTemp) { return pTemp->count; }

Boolean _searchList(List *pTemp, ListNode **ppPre, ListNode **ppPos,
                    Element data) {
  for (*ppPre = NULL, *ppPos = pTemp->head; *ppPos != NULL;
       *ppPre = *ppPos, *ppPos = (*ppPos)->next) {
    if ((*ppPos)->data ==
        data) // 해당 노드 발견 시 위치를 간접적으로 저장 후 break
    {
      return 1;
    }

    else if ((*ppPos)->data > data) // 찾는 범위 내에 없을 경우 (시간 단축)
    {
      break;
    }
  }

  return 0;
}

void _insertList(List *pTemp, ListNode *pPre, Element data) {
  ListNode *pTempNode = (ListNode *)malloc(sizeof(ListNode));
  if (pTempNode == NULL) {
    return;
  }

  if (pPre == NULL) // 리스트 가장 앞에 삽입
  {
    pTempNode->next = pTemp->head;
    pTemp->head = pTempNode;
  }

  else // 리스트 중간에 삽입
  {
    pTempNode->next = pPre->next;
    pPre->next = pTempNode;
  }

  pTempNode->data = data;
  pTemp->count++;
}

void _deleteList(List *pTemp, ListNode *pPre, ListNode *pPos) {
  if (pPre == NULL) // 리스트 가장 앞을 삭제
  {
    pTemp->head = pPos->next;
  }

  else // 리스트 중간을 삭제
  {
    pPre->next = pPos->next;
  }

  free(pPos);
  pTemp->count--;
}

List *CreateList() {
  List *pTemp = (List *)malloc(sizeof(List));
  if (pTemp == NULL) {
    return NULL;
  }

  pTemp->count = 0;
  pTemp->head = NULL;

  return pTemp;
}

void AddNode(List *pTemp, Element data) {
  ListNode *pPre = NULL, *pPos = NULL;
  Boolean found = _searchList(pTemp, &pPre, &pPos, data);

  if (found == 0) // 리스트에 겹치는 게 없을 경우
  {
    _insertList(pTemp, pPre, data);
  }

  else // 리스트에 겹치는 게 있을 경우
  {
    printf("\n%d is Already in The List.\n", data);
  }
}

void RemoveNode(List *pTemp, Element data) {
  ListNode *pPre = NULL, *pPos = NULL;
  Boolean found = _searchList(pTemp, &pPre, &pPos, data);

  if (found == 1) // 리스트에 해당 데이터가 있을 경우
  {
    printf("\n%d was removed.\n", data);
    _deleteList(pTemp, pPre, pPos);
  }

  else // 리스트에 해당 데이터가 없을 경우
  {
    printf("\n%d is Not in The List.\n", data);
  }
}

Boolean SearchNode(List *pTemp, Element data) {
  ListNode *pPre = NULL, *pPos = NULL;
  Boolean found = _searchList(pTemp, &pPre, &pPos, data);

  return found;
}

void DestroyList(List *pTemp) {
  ListNode *pPre = NULL, *pPos = NULL;

  for (pPre = pTemp->head; pPre != NULL; pPre = pPos) {
    pPos = pPre->next;
    free(pPre);
  }

  free(pTemp);
}

void ShowList(List *pTemp) {
  ListNode *pPre = NULL, *pPos = NULL;

  for (pPre = pTemp->head; pPre != NULL; pPre = pPos) {
    pPos = pPre->next;
    printf("%d", pPre->data);
    if (pPos != NULL) {
      printf(", ");
    }
  }
}

Boolean IsEmptyList(List *pTemp) {
  if (_listCount(pTemp) == 0) {
    return 1;
  }

  else {
    return 0;
  }
}
