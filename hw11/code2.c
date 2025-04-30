// 2020116706 전영원

#include <stdio.h>

int fibonacci(int prev_number, int number);
int count;



void main()
{
	int a = 0;
	int b = 1;

	printf("피보나치를 몇 개 구할까요?(3 이상의 정수 입력) : ");
	scanf("%d", &count);

	fibonacci(a, b);
}



int fibonacci(int prev_number, int number)
{
	static int i = 1;

	while (i <= count)
	{
		i++;
		int next_number = number + prev_number;

		printf("%d ", number);

		prev_number = number;
		number = next_number;

		fibonacci(prev_number, number);
	}
}