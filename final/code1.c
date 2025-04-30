// 2020116706 전영원

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pick()
{
	return rand() % 45 + 1;
}



void main()
{
	srand((long)time NULL);

	int a[7];

	for (int i = 0; i < 7; i++)
	{
		a[i] = pick();

		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				i--;
				break;
			}
		}
	}

	printf("로또 당첨 번호는 ");

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}

	printf("이고\n보너스 번호는 %d 입니다.", a[6]);
}