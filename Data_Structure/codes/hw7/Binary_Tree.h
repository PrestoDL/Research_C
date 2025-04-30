// 2020116706

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Element;
typedef int Boolean;

typedef struct Ttree {
  Element data;
  struct Ttree *left, *right;
} Tree;

Tree *CreateTree(Tree *left, Element item, Tree *right) {
  Tree *pTemp = (Tree *)malloc(sizeof(Tree));
  if (pTemp == NULL) {
    return NULL;
  }

  pTemp->data = item;
  pTemp->left = left;
  pTemp->right = right;

  return pTemp;
}

Boolean IsEmptyTree(Tree *pTemp) {
  if ((pTemp->left == NULL) && (pTemp->right == NULL)) {
    return 1;
  }

  else {
    return 0;
  }
}

Tree *LeftTree(Tree *pTemp) {
  if (IsEmptyTree(pTemp) == 1) {
    return;
  }

  return pTemp->left;
}

Tree *RightTree(Tree *pTemp) {
  if (IsEmptyTree(pTemp) == 1) {
    return;
  }

  return pTemp->right;
}

Element TreeData(Tree *pTemp) {
  if (pTemp == NULL) {
    return;
  }

  return pTemp->data;
}

void DestroyTree(Tree *pTemp) {
  if (pTemp == NULL) {
    return;
  }

  if (pTemp->left != NULL) {
    DestroyTree(pTemp->left);
  }

  if (pTemp->right != NULL) {
    DestroyTree(pTemp->right);
  }

  free(pTemp);
}