#include "sort.h"

typedef int Boolean;

Boolean binary(Element *pTemp, int target) {
  int count = intLen(pTemp);
  int s = 0;
  int f = count - 1;
  int mid = ((s + f) / 2);
  selection(&pTemp);

  while ((s != f) && (pTemp[mid] != target)) {
    if (target < pTemp[mid]) {
      f = mid - 1;
    }

    else {
      s = mid + 1;
    }

    mid = ((s + f) / 2);
  }

  if (pTemp[mid] == target) {
    return 1;
  }

  else {
    return 0;
  }
}

int hashfunc(int input) {
  return (input * input) % 12345;
} // (key 값의 제곱) mod (12345)를 해시 값으로 지정.

Boolean hash(Element *pTemp, int target) {
  int count = intLen(pTemp);
  int hashArray[12345][4]; // bucket hashing : bucket의 크기를 4로 지정.

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < 4; j++) {
      if (hashArray[hashfunc(pTemp[i])][j] == '\0') {
        hashArray[hashfunc(pTemp[i])][j] = pTemp[i];
        break;
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    if (hashArray[hashfunc(target)][i] == target) {
      return 1;
    }
  }

  return 0;
}