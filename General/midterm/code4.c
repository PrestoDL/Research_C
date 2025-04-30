// 2020116706 전영원

#include <stdio.h>

void main()
{
	int a;
	int b;
	int c;

	int d;

	int f;
	int x;

	do
	{
		printf("행의 수를 3 이상의 홀수로 입력하세요 : ");
		scanf("%d", &f);
	} while (f < 3 || f % 2 - 1);
	
	x = (f - 1) / 2;

	for (a = 1; a <= x; a++)
	{
		for (b = 0; b < a; b++)
		{
			printf("*");
		}
		for (c = 0; c < f - 2 * a + 1; c++)
		{
			printf(" ");
		}
		for (b = 0; b < a; b++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (d = 0; d < f + 1; d++)
	{
		printf("*");
	}
	printf("\n");

	for (a = 1; a <= x; a++)
	{
		for (b = 0; b < x - a + 1; b++)
		{
			printf("*");
		}
		for (c = 0; c < 2 * a; c++)
		{
			printf(" ");
		}
		for (b = 0; b < x - a + 1; b++)
		{
			printf("*");
		}
		printf("\n");
	}
}