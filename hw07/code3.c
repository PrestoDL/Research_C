//2020116706 전영원

#include <stdio.h>

void main()
{
	double t;

	int* pt = &t;

	printf("두 정수를 입력하세요 : ");
	scanf("%d %d", pt, pt+1);


	printf("%d + %d = %d\n", *pt, *(pt + 1), *pt + *(pt + 1));
	printf("%d - %d = %d\n", *pt, *(pt + 1), *pt - *(pt + 1));
	printf("%d X %d = %d\n", *pt, *(pt + 1), *pt * *(pt + 1));
	printf("%d / %d = %d\n", *pt, *(pt + 1), *pt / *(pt + 1));
}