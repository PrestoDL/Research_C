// 2020116706 전영원

#include <stdio.h>

void main()
{
	float h;
	float w;

	printf("신장(cm) : ");
	scanf("%f", &h);
	printf("몸무게(kg) : ");
	scanf("%f", &w);
	
	float bmi = w * 10000 / (h * h);
	printf("bmi지수는 %3.1f 이고, ", bmi);


	if (bmi > 30)
	{
		printf("중등도비만입니다.");
	}


	else if (bmi > 25)
	{
		printf("경도도비만입니다.");
	}


	else if (bmi > 23)
	{
		printf("과체중입니다.");
	}


	else if (bmi > 18.5)
	{
		printf("정상입니다.");
	}


	else
	{
		printf("저체중입니다.");
	}
}