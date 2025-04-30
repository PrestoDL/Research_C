//2020116706 전영원

#include <stdio.h>

void reverse(char* pt)
{
	int l = strlen(pt);

	printf("입력한 단어를 반대로 출력합니다 : ");

	for (int i = l; i > 0; i--)
	{
		printf("%c", pt[i - 1]);
	}
}



void main()
{
	char a[50];

	printf("한 단어를 입력하세요 : ");
	gets(a);

	reverse(a);
}