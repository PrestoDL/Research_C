#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Element;

int intLen(int *arr) {
  int count = 0;
  for (int i = 0; arr[i] != '\0'; i++) {
    count++;
  }
  return count;
}

void printArray(Element *pTemp) {
  int count = intLen(pTemp);

  for (int i = 0; i < count; i++) {
    printf("\n%d", pTemp[i]);
  }
}

void _moveArray(Element **ppTemp, int f, int t) {
  if (f == t) {
    return;
  }

  else if (f < t) {
    Element temp = (*ppTemp)[f];
    for (int i = 0; i < (t - f); i++) {
      (*ppTemp)[f + i] = (*ppTemp)[f + i + 1];
    }
    (*ppTemp)[t] = temp;
  }

  else {
    Element temp = (*ppTemp)[f];
    for (int i = 0; i < (f - t); i++) {
      (*ppTemp)[f - i] = (*ppTemp)[f - i - 1];
    }
    (*ppTemp)[t] = temp;
  }
}

void _swapArray(Element **ppTemp, int a, int b) {
  Element Temp = (*ppTemp)[a];
  (*ppTemp)[a] = (*ppTemp)[b];
  (*ppTemp)[b] = Temp;
}

void selection(Element **ppTemp) {
  int count = intLen(*ppTemp);

  for (int wall = 0; wall < (count - 1); wall++) {
    int minIndex = wall;

    for (int i = 1; i < (count - wall); i++) {
      if ((*ppTemp)[minIndex] > (*ppTemp)[i + wall]) {
        minIndex = i + wall;
      }
    }

    _moveArray(ppTemp, minIndex, wall);
  }
}

void insertion(Element **ppTemp) {
  int count = intLen(*ppTemp);

  for (int wall = 1; wall < count; wall++) {
    int minIndex = wall;

    for (int i = 0; i < wall; i++) {
      if ((*ppTemp)[i] > (*ppTemp)[wall]) {
        minIndex = i;
        break;
      }
    }

    _moveArray(ppTemp, wall, minIndex);
  }
}

void bubble(Element **ppTemp) {
  int count = intLen(*ppTemp);

  for (int wall = 1; wall < count; wall++) {
    for (int i = (count - 1); i > (wall - 1); i--) {
      if ((*ppTemp)[i - 1] > (*ppTemp)[i]) {
        _moveArray(ppTemp, i, i - 1);
      }
    }
  }
}

void _launchQuick(Element **ppTemp, int s, int f) {
  if (s < f) {
    int pivot = (*ppTemp)[s];
    int l = s + 1;
    int r = f;

    while (l - 1 < r) {
      while ((*ppTemp)[l] < pivot) {
        l++;
      }

      while ((*ppTemp)[r] > pivot) {
        r--;
      }

      if (l < r) {
        _swapArray(ppTemp, l, r);
      }
    }

    _moveArray(ppTemp, s, r);

    _launchQuick(ppTemp, s, r - 1);
    _launchQuick(ppTemp, l, f);
  }
}

void quick(Element **ppTemp) { _launchQuick(ppTemp, 0, (intLen(*ppTemp) - 1)); }

void _MergeNode(Element **ppTemp, int s, int mid, int f) {
  int l = s;
  int r = mid + 1;

  while ((l <= mid) && (r <= f)) {
    if ((*ppTemp)[l] < (*ppTemp)[r]) {
      l++;
    }

    else {
      _moveArray(ppTemp, r++, l++);
      mid++;
    }
  }
}

void _launchMerge(Element **ppTemp, int s, int f) {
  if (s < f) {
    int mid = (s + f) / 2;
    _launchMerge(ppTemp, s, mid);
    _launchMerge(ppTemp, mid + 1, f);
    _MergeNode(ppTemp, s, mid, f);
  }
}

void merge(Element **ppTemp) { _launchMerge(ppTemp, 0, (intLen(*ppTemp) - 1)); }