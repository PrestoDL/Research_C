// 2020116706 전영원

#include <stdio.h>

void main()
{
	int month;
	printf("월(month)를 입력하세요 : ");
	scanf("%d", &month);

	switch (month)
	{
	case 1 : case 2 : case 3 :
		printf("%d월은 1사분기입니다.", month);
		break;

	case 4: case 5: case 6:
		printf("%d월은 2사분기입니다.", month);
		break;

	case 7: case 8: case 9:
		printf("%d월은 3사분기입니다.", month);
		break;

	case 10: case 11: case 12:
		printf("%d월은 4사분기입니다.", month);
		break;

	default :
		printf("잘못된 값입니다.");
	}
}