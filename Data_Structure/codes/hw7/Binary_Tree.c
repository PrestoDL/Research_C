// 2020116706

#include "Tree_Queue.h"

void StringPre(Tree *pTemp) { // PreOrder 출력
  if (pTemp == NULL) {
    return;
  }
  printf("%c", pTemp->data);
  StringPre(pTemp->left);
  StringPre(pTemp->right);
}

void StringIn(Tree *pTemp) { // InOrder 출력
  if (pTemp == NULL) {
    return;
  }
  StringIn(pTemp->left);
  printf("%c", pTemp->data);
  StringIn(pTemp->right);
}

void StringPost(Tree *pTemp) { // PostOrder 출력
  if (pTemp == NULL) {
    return;
  }
  StringPost(pTemp->left);
  StringPost(pTemp->right);
  printf("%c", pTemp->data);
}

void StringBreadth(Tree *pRoot) { // Breadth-First 출력
  if (pRoot == NULL) {
    return;
  }
  Tree **ppTemp;
  ppTemp = &pRoot;
  Queue *q = CreateQueue();

  while (*ppTemp != NULL) {
    printf("%c", (*ppTemp)->data);
    Enqueue(q, &(*ppTemp)->left);
    Enqueue(q, &(*ppTemp)->right);
    ppTemp = Dequeue(q);
  }

  DestroyQueue(q);
}

Tree *TreeString(char *s) { // 입력된 문자열을 토대로 트리 생성
  Tree *pRoot;
  Tree **ppTemp;
  Queue *q = CreateQueue();
  int c = strlen(s);
  ppTemp = &pRoot;

  for (int i = 0; i < c; i++) {
    *ppTemp = CreateTree(NULL, s[i], NULL);
    Enqueue(q, &(*ppTemp)->left);
    Enqueue(q, &(*ppTemp)->right);
    ppTemp = Dequeue(q);
  }

  DestroyQueue(q);
  return pRoot;
}

int main(void) {
  char s[100];
  printf("Input a String : ");
  scanf("%s", s);

  Tree *root = TreeString(s);

  printf("\n\nPre-Order : ");
  StringPre(root);

  printf("\n\nIn-Order : ");
  StringIn(root);

  printf("\n\nPost-Order : ");
  StringPost(root);

  printf("\n\nBreadth First : ");
  StringBreadth(root);

  DestroyTree(root);
  return 0;
}