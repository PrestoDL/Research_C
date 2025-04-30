// 2020116706 전영원

#include <stdio.h>

void main()
{
	int i;
	int max;
	int div;
	int line = 1;

	printf("2부터 n까지의 소수를 구합니다. 2보다 큰 정수 n을 입력하세요 : ");
	scanf("%d", &max);

	for (i = 2; i <= max; i++)
	{
		for (div = 2; i % div; div++);
		{
			if (div == i)
			{
				printf("%d%c", i, (line++ % 10) ? ' ' : '\n');
			}
		}
	}
}