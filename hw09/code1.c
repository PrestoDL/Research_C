// 2020116706 전영원

#include <stdio.h>

int intpow(m, n)
{
	int total = 1;

	for (int i = 0; i < n; i++)
	{
		total = total * m;
	}
	return total;
}



void main()
{
	int m;
	int n;

	printf("정수 m을 n번 제곱합니다.\n\n");

	printf("정수 m 입력 -> ");
	scanf("%d", &m);

	printf("정수 n 입력 -> ");
	scanf("%d", &n);

	printf("%d의 %d제곱은 %d입니다.\n", m, n, intpow(m, n));
}