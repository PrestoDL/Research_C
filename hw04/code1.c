// 2020116706 전영원

#include <stdio.h>

void main()
{
	int a;
	printf("각도 : ");
	scanf("%d", &a);

	if (0 < a && a < 90)
	{
		printf("1사분면");
	}


	else if (90 < a && a < 180)
	{
		printf("2사분면");
	}


	else if (180 < a && a < 270)
	{
		printf("3사분면");
	}


	else if (270 < a && a < 360)
	{
		printf("4사분면");
	}


	else if (a == 0)
	{
		printf("양의 x축");
	}


	else if (a == 90)
	{
		printf("양의 y축");
	}


	else if (a == 180)
	{
		printf("음의 x축");
	}


	else if (a == 270)
	{
		printf("음의 y축");
	}


	else if (a == 360)
	{
		printf("양의 x축");
	}


	else
	{
		printf("잘못된 값입니다.");
	}
}