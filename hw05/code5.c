// 2020116706 전영원

#include <stdio.h>

void main()
{
	int n;
	int i;

	printf("정수 또는 0(종료)을 입력 : ");
	scanf("%d", &n);

	while (n)
	{
		printf("정수 %d의 32비트 내부 값 : \n", n);
		for (i = 31; i >= 0; i--)
		{
			printf("%d", (n >> i) & 1);
		}

		printf("\n정수 또는 0(종료)을 입력 : ");
		scanf("%d", &n);
	}
}