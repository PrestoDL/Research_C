// 2020116706 전영원

#include <stdio.h>

int square(a)
{
	return a * a;
}

int cube(a)
{
	return square(a) * a;
}

int five(a)
{
	return square(a) * cube(a);
}



void main()
{
	int n;

	printf("정수 입력 -> ");
	scanf("%d", &n);

	printf("%d의 제곱은 %d입니다.\n", n, square(n));
	printf("%d의 세제곱은 %d입니다.\n", n, cube(n));
	printf("%d의 다섯제곱은 %d입니다.\n", n, five(n));
}