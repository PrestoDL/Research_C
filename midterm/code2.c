// 2020116706 전영원

#include <stdio.h>

void main()
{
	int n;
	int i = 0;
	int sum = 0;

	int a = 0;
	int b = 0;
	int avg;     //홀수들의 개수, 합, 평균이 모두 정수형으로 나올 수 있다고 판단하여 실수형을 사용하지 않았습니다.

	printf("숫자를 입력하세요 : ");
	scanf("%d", &n);

	printf("\n1부터 n까지의 합 중에서 %d를 넘지 않는 가장 큰 합을 구합니다.\n", n);
	while (sum + i < n)
	{
		i++;
		sum = sum + i;
		if (i % 2)
		{
			a++;
			b = b + i;
		}
	}
	printf("1부터 %d까지의 합은 %d입니다.\n", i, sum);

	if (a > 0)
	{
		printf("1부터 %d까지의 숫자 중 홀수들의 개수는 %d입니다.\n", i, a);
		printf("1부터 %d까지의 숫자 중 홀수들의 합은 %d입니다.\n", i, b);
		avg = b / a;
		printf("1부터 %d까지의 숫자 중 홀수들의 평균은 %d입니다.\n", i, avg);
	}
	else
	{
		printf("홀수는 없습니다.");
	}
}