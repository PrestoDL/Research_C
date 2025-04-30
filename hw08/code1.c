//2020116706 전영원

#include <stdio.h>

#define sizea 5
#define sizeb 7

void main()
{
	int a[] = { 32, 56, 7, 8, 24 };
	int b[] = { 3, 21, 35, 57, 24, 82, 8 };

	int as = sizeof(a) / sizeof(a[0]);
	int bs = sizeof(b) / sizeof(b[0]);
	int cs = as + bs;
	int c[sizea + sizeb];

	for (int i = 0; i < cs; i++)
	{
		if (i < as)
		{
			c[i] = a[i];
		}
		else
		{
			c[i] = b[i - as];
		}
	}

	printf("두 배열을 연결한 배열의 원소 값을 출력\n");

	for (int j = 0; j < cs; j++)
	{
		printf("%d ", c[j]);
	}
	printf("\n");
}