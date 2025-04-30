// 2020116706 전영원

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number;
static int min = 0;
static int max = 100;

int setNumber()
{
	return (rand() % 100) + 1;
}

void printHead()
{
	printf("1에서 100까지의 정수 중 하나가 결정되었습니다.\n");
	printf("이 정수를 맞추어 보세요.\n > ");
}

void printHigher(int a)
{
	min = a;
	printf("\n맞추어야 할 정수가 입력한 정수 %d보다 큽니다.\n", a);
	printf("%3d 이상, %3d 이하의 정수를 다시 입력하세요.\n > ", min, max);
}

void printLower(int a)
{
	max = a;
	printf("\n맞추어야 할 정수가 입력한 정수 %d보다 작습니다.\n", a);
	printf("%3d 이상, %3d 이하의 정수를 다시 입력하세요.\n > ", min, max);
}

void printAnswer(int a)
{
	printf("\n축하합니다! 정답은 %3d 입니다.\n\n", a);
}



void main()
{
	long sec = (long)time(NULL);
	srand(sec);

	number = setNumber();

	int a;
	printHead();

	do
	{
		scanf("%d", &a);

		if (a == number)
		{
			printAnswer(a);
		}

		if (a < number)
		{
			printHigher(a);
		}
		
		if (a > number)
		{
			printLower(a);
		}
	} while (a != number);
}