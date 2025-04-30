// 2020116706 전영원

#include <stdio.h>

struct lecture
{
	char name[20];
	int type;
	int credit;
	int hours;
};



void main()
{
	struct lecture a[5];
	struct lecture* p[5];

	for (int i = 0; i < 5; i++)
	{
		p[i] = &a[i];

		puts("강좌 정보를 입력하세요.\n");
		printf("강좌명 : ");
		scanf("%s", &(*p[i]).name);
		printf("강좌 구분   (0)교양  (1)일반선택  (2)전공필수  (3)전공선택 : ");
		scanf("%d", &(*p[i]).type);
		printf("학점 : ");
		scanf("%d", &(*p[i]).credit);
		printf("시수 : ");
		scanf("%d", &(*p[i]).hours);
		puts("\n");
	}

	char* head[] = { "강좌명", "강좌구분", "학점", "시수" };
	char* lectype[] = { "교양", "일반선택", "전공필수", "전공선택" };

	for (int i = 0; i < 4; i++)
	{
		printf("%12s", head[i]);
	}

	puts("\n================================================");
	for (int i = 0; i < 5; i++)
	{
		printf("%12s", (*p[i]).name);
		printf("%12s", lectype[(*p[i]).type]);
		printf("%11d", (*p[i]).credit);
		printf("%12d", (*p[i]).hours);
		puts("");
	}
}