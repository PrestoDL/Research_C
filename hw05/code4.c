// 2020116706 전영원

#include <stdio.h>

void main()
{
	int a;
	int b;
	int n;
	int max;

	printf("피라미드의 층을 입력하세요 : ");
	scanf("%d", &max);

	for (n = 1; n <= max; n++)
	{

		for (a = 1; a <= max - n; a++)
		{
			printf(" ");
		}

		for (b = 1; b <= 2 * n - 1; b++)
		{
			printf("*");
		}

		printf("\n");
	}
}