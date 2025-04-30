// 2020116706 전영원

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random()
{
	return (rand() % 100) + 1;
}

void incrementary(int ary[], int n, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		ary[i] = ary[i] + n;
	}
}

void printary(int* data, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%4d", data[i]);
	}
}



void main()
{
	int n;
	int data[10];

	long sec = (long)time(NULL);
	srand(sec);

	for (int i = 0; i < 10; i++)
	{
		data[i] = random();
	}

	printary(data, 10);

	printf("\n더할 수를 입력하세요 : ");
	scanf("%d", &n);

	incrementary(data, n, 10);

	printary(data, 10);
}