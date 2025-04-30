//2020116706 전영원

#include <stdio.h>

void main()
{
	int n1;
	int n2;

	printf("두 정수를 입력하세요 : ");
	scanf("%d %d", &n1, &n2);

	int* p1 = &n1;
	int* p2 = &n2;

	int** dp = &p1;
	int sum = **dp;

	dp = &p2;
	sum += **dp;

	printf("첫 번째 정수 : %d\n", *p1);
	printf("두 번째 정수 : %d\n", *p2);
	printf("합 : %d\n", sum);
}