// 2020116706 전영원

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random()
{
	return (rand() % 45) + 1;
}



void main()
{
	int a[6];

	long sec = (long)time(NULL);
	srand(sec);

	printf("로또 당첨 번호는");

	for (int i = 0; i < 6; i++)
	{
		a[i] = random();

		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				a[i] = random();
				j--;
			}
		}
		printf("%3d,", a[i]);
	}
	printf(" 입니다.\n");
}

