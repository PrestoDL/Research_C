// 2020116706 전영원

#include <stdio.h>

int call(int n)
{
	static int a = 0;
	int sum = 0;

	if (n > 0)
	{
		a++;
		printf("%d번 호출\n", a);
		sum = n + call(n - 1);
	}
	return sum;
}


void main()
{
	int n;

	printf("양의 정수를 입력 : ");
	scanf("%d", &n);

	printf("sum = %d", call(n));
}