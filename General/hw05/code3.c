// 2020116706 전영원

#include <stdio.h>

void main()
{
	int n;
	int sum;

	printf("1부터 n까지의 합 중에서 10000을 넘기지 않는 가장 큰 합은?\n");

	for (n = 1, sum = 0; sum <= 10000; n++)
	{
		sum = sum + n;
		if (sum + n > 10000)
		{
			break;
		}
	}
	printf("=> 1부터 %d까지의 합이 %d입니다.", n, sum);
}