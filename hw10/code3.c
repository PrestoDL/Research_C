//2020116706 전영원

#include <stdio.h>

void delchar(char str[], char* ch)
{
	int a = strlen(str);
	char c = *ch;

	for (int i = 0; i < a; i++)
	{
		if (str[i] == c)
		{
			str[i] = ' ';
		}
	}
}



void main()
{
	char a[50];
	char d[1];

	printf("문자열을 입력하세요 : ");
	gets(a);

	printf("지울 문자를 입력하세요 : ");
	scanf("%c", d);

	printf("\n%c를 삭제한 후\n", *d);
	printf("-> %s\n", a);
	delchar(a, d);
	printf("-> %s\n", a);
}