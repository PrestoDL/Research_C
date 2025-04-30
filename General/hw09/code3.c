// 2020116706 전영원

#include <stdio.h>

int sum(a)
{
	if (a <= 0)
	{
		return 0;
	}

	else
	{
		return (a + sum(a - 1));
	}
}



void main()
{
	int a;

	printf("숫자를 입력하세요 : ");
	scanf("%d", &a);
	
	printf("\n1부터 %d까지 각각의 합을 구하는 프로그램입니다.\n\n", a);

	for (int i = 1; i <= a; i++)
	{
		printf("1부터 %4d까지의 합 : %5d\n", i, sum(i));
	}
}