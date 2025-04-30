// 2020116706 전영원

#include <stdio.h>

void main()
{
	float x;
	float y;
	float z;
	printf("x값을 입력하세요. : ");
	scanf("%f", &x);
	printf("y값을 입력하세요. : ");
	scanf("%f", &y);

	if (x > 0)
	{
		if (y > 0)
		{
			z = x + y;
		}

		else
		{
			z = x - y;
		}
	}

	else
	{
		if (y > 0)
		{
			z = -x + y;
		}

		else
		{
			z = -x - y;
		}
	}
	printf("연산 값은 %f 입니다.", z);
}