// 2020116706 전영원

#include <stdio.h>

int count;

void fibonacci(int prev_number, int number)
{
	static int i = 1;

	if (i <= count)
	{
		i++;
		int next_number = prev_number + number;

		printf("%d ", number);

		prev_number = number;
		number = next_number;
		
		fibonacci(prev_number, number);
	}
}



void main()
{
	printf("피보나치를 몇 개 구할까요(3 이상)? : ");
	scanf("%d", &count);

	int prev_number = 0;
	int number = 1;

	fibonacci(prev_number, number);
}