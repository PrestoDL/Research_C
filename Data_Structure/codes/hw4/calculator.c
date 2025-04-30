// 2020116706

#include "Stack_Array.h" // Array 스택의 경우 include
//#include "Stack_Link.h" // Link 스택의 경우 include
#include <string.h>

int prop(char i) {
  switch (i) {
  case '(':
  case ')':
    return 1;

  case '+':
  case '-':
    return 2;

  case '*':
  case '/':
  case '%':
    return 3;
  }

  return 0;
}

void calc(Stack **stack, int oper) {
  int result;
  int tp1 = Pop(*stack);
  int tp2 = Pop(*stack);

  switch (oper) {
  case '+':
    result = tp2 + tp1;
    break;

  case '-':
    result = tp2 - tp1;
    break;

  case '*':
    result = tp2 * tp1;
    break;

  case '/':
    result = tp2 / tp1;
    break;

  case '%':
    result = tp2 % tp1;
    break;
  }
  Push(*stack, result);
}

int postize(Stack *write, char in[50]) {
  char token;
  char sin;
  int temp;
  int bincheck = 0;
  char numtemp[10] = "";
  int len = strlen(in);

  Stack *res;
  res = CreateStack(50);

  printf("\nPost  : ");

  for (int i = 0; i < len; i++) {
    token = in[i];

    switch (token) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
      if (bincheck == 1 || bincheck == 3) {
        bincheck = 0;

        while ((IsEmptyStack(write) == 0) &&
               (prop(token) <= prop(Top(write)))) {
          sin = Pop(write);
          printf("%c ", sin); //연산자 출력
          calc(&res, (int)sin);
        }
        Push(write, token);
      }

      else {
        printf("\n\nError : Check the binary expression!\n\n");
        exit(0);
      }

      break;

    case '(':
      if (bincheck == 0 || bincheck == 2) {
        bincheck = 2;

        Push(write, token);
      }

      else {
        printf("\n\nError : Check the binary expression!\n\n");
        exit(0);
      }

      break;

    case ')':
      if (bincheck == 1 || bincheck == 3) {
        bincheck = 3;

        sin = Pop(write);
        while (sin != '(') {
          printf("%c ", sin); //괄호 기준 남은 연산자 출력
          calc(&res, sin);
          sin = Pop(write);
        }
      }

      else {
        printf("\n\nError : Check the binary expression!\n\n");
        exit(0);
      }

      break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      numtemp[strlen(numtemp)] = token;
      if ((in[i + 1] != '0') && (in[i + 1] != '1') && (in[i + 1] != '2') &&
          (in[i + 1] != '3') && (in[i + 1] != '4') && (in[i + 1] != '5') &&
          (in[i + 1] != '6') && (in[i + 1] != '7') && (in[i + 1] != '8') &&
          (in[i + 1] != '9')) {
        if (bincheck == 0 || bincheck == 2) {
          bincheck = 1;

          temp = atoi(numtemp);
          printf("%d ", temp); //숫자 덩어리 출력
          Push(res, temp);

          for (int j = 0; j < 10; j++) {
            numtemp[j] = 0;
          }
        }

        else {
          printf("\n\nError : Check the binary expression!\n\n");
          exit(0);
        }
      }
      break;

    default:
      break;
    }
  }

  while (IsEmptyStack(write) == 0) {
    sin = Pop(write);
    printf("%c ", sin); //남은 연산자 출력
    calc(&res, sin);
  }

  return Top(res);
}

int main(void) {
  char in[50];
  Stack *write;
  write = CreateStack(50);

  printf("Arithmetic Expression : ");
  gets(in);

  int partcount1 = 0;
  int partcount2 = 0;
  for (int part = 0; part < strlen(in); part++) {
    if (in[part] == '(') {
      partcount1++;
    } else if (in[part] == ')') {
      partcount2++;
    }
  }
  if (partcount1 != partcount2) {
    printf("\nError : Check the pairs of Parenthesis!\n\n");
    exit(0);
  }

  printf("\nInput : %s", in);

  printf("\nResult : %d", postize(write, in));

  printf("\n\n");

  DestroyStack(write);

  return 0;
}