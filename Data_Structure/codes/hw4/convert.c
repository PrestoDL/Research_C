// 2020116706

#include "Stack_Array.h" // Array 스택의 경우 include
//#include "Stack_Link.h" // Link 스택의 경우 include

int main(void) {
  int num;
  int temp;
  Stack *write;
  write = CreateStack(32);

  printf("Enter the Number to convert : ");
  scanf("%d", &num);
  if (num <= 0) {
    printf("\nInput must be POSITIVE Number. ( 1 ~ 2147483647 )\n\n");
    return 0;
  }

  Push(write, num);

  while (Top(write) != 1) {
    temp = Pop(write);
    Push(write, temp % 2);
    Push(write, temp / 2);
  }

  printf("\nThe binary Number of %d : ", num);

  while (IsEmptyStack(write) == 0) {
    printf("%d", Pop(write));
  }
  printf("\n\n");

  return 0;
}
