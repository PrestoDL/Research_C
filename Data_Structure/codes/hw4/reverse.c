// 2020116706

#include "Stack_Array.h" // Array 스택의 경우 include
//#include "Stack_Link.h" // Link 스택의 경우 include

void input(Stack *write) {
  int a;
  int check;
  while (1) {
    printf("Enter a number, 'Ctrl + D' to stop : ");
    scanf("%d", &a);
    check = getchar();
    if (check == EOF) {
      break;
    }
    Push(write, a);
  }
}

int main(void) {
  Stack *write;
  write = CreateStack(50);

  input(write);

  printf("\n\n[The List of Number Reversed]\n\n");

  while (IsEmptyStack(write) == 0) {
    printf("%d\n", Pop(write));
  }

  return 0;
}
