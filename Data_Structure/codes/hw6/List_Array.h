#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef int Boolean;

typedef struct {
  Element *array;
  int size;
  int count;
} List;

int _listCount(List *pTemp) { return pTemp->count; }

int _searchList(List *pTemp, Element data) {
  int i;
  int c = _listCount(pTemp);
  for (i = 0; i < c; i++) {
    if (pTemp->array[i] == data) {
      return i; // 같은 데이터가 있을 경우, 그 순서를 반환.
    }

    else if (pTemp->array[i] > data) {
      break;
    }
  }

  return -(i + 1); // 같은 데이터가 없을 경우, (크기상의 순서의 음수)-1 반환
}

void _insertList(List *pTemp, int n, Element data) {
  if (_listCount(pTemp) == pTemp->size) {
    printf("\nThe List is Full.\n");
    return;
  }

  for (int i = _listCount(pTemp); i > n; i--) {
    pTemp->array[i] = pTemp->array[i - 1];
  }

  pTemp->array[n] = data;
  pTemp->count++;
}

void _deleteList(List *pTemp, int n) {
  int c = _listCount(pTemp);

  if (c == 0) {
    printf("\nThe List is Empty.\n");
    return;
  }

  for (int i = n; i < c - 1; i++) {
    pTemp->array[i] = pTemp->array[i + 1];
  }

  pTemp->count--;
}

List *CreateList(int size) {
  List *pTemp = (List *)malloc(sizeof(List));
  if (pTemp == NULL) {
    return NULL;
  }

  pTemp->array = (Element *)malloc(size * sizeof(Element));
  if (pTemp->array == NULL) {
    return NULL;
  }

  pTemp->size = size;
  pTemp->count = 0;

  return pTemp;
}

void AddNode(List *pTemp, Element data) {
  Boolean order = _searchList(pTemp, data);

  if (order < 0) // 리스트에 겹치는 게 없을 경우
  {
    _insertList(pTemp, -order - 1, data);
  }

  else // 리스트에 겹치는 게 있을 경우
  {
    printf("\n%d is Already in The List.\n", data);
  }
}

void RemoveNode(List *pTemp, Element data) {
  Boolean order = _searchList(pTemp, data);

  if (order >= 0) // 리스트에 해당 데이터가 있을 경우
  {
    printf("\n%d was removed.\n", data);
    _deleteList(pTemp, order);
  }

  else // 리스트에 해당 데이터가 없을 경우
  {
    printf("\n%d is Not in The List.\n", data);
  }
}

Boolean SearchNode(List *pTemp, Element data) {
  if (_searchList(pTemp, data) >= 0) {
    return 1;
  }

  else {
    return 0;
  }
}

void DestroyList(List *pTemp) {
  int c = _listCount(pTemp);
  for (int i = 0; i < c; i++) {
    free(pTemp->array);
    free(pTemp);
  }
}

void ShowList(List *pTemp) {
  int c = _listCount(pTemp);
  for (int i = 0; i < c; i++) {
    if (i != 0) {
      printf(", ");
    }
    printf("%d", pTemp->array[i]);
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

Boolean IsFullList(List *pTemp) {
  if (_listCount(pTemp) == pTemp->size) {
    return 1;
  }

  else {
    return 0;
  }
}