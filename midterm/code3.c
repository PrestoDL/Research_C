// 2020116706 전영원

#include <stdio.h>
#define b 16

void main()
{
	int a;
	int i;

	printf("정수 또는 0(종료)을 입력 : ");
	scanf("%d", &a);

	while (a)
	{
		printf("정수 %d의 16비트 내부 값 :\n", a);
		for (i = b; i > 0; i--)
		{
			printf("%d", a >> (i-1) & 1);
		}

		printf("\n\n정수 또는 0(종료)을 입력 : ");
		scanf("%d", &a);
	}

	printf("\n프로그램을 종료합니다.\n");
}