// 2020116706 전영원

#include <stdio.h>

void main()
{
	int y;
	int m;
	int d;
	int a;

	printf("년과 월을 입력하세요 : ");
	scanf("%d %d", &y, &m);

	if (y % 400)
	{
		if (y % 100)
		{
			if (y % 4)
			{
				a = 1;
			}

			else
			{
				a = 2;
			}
		}

		else
		{
			a = 1;
		}
	}

	else
	{
		a = 2;
	}

	if (1 <= m && m <= 12)
	{
		switch (m)
		{
		case 4: case 6: case 9: case 11:
			d = 30;
			break;
		case 2:
			if (a == 1)
			{
				d = 28;
			}
			else
			{
				d = 29;
			}
			break;
		default:
			d = 31;
			break;
		}
		printf("%d년 %d월의 말일은 %d일 입니다.", y, m, d);
	}

	else
	{
		printf("잘못된 월을 입력하였습니다.");
	}
}