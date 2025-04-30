// 2020116706 전영원

#include <stdio.h>
#include <string.h>

void delchar(char str[], char ch)
{
	int a = strlen(str);

	for (int i = 0; i < a; i++)
	{
		if (str[i] == ch)
		{
			str[i] = ' ';
		}

		if (str[i] == ' ')
		{
			for (int j = i; j < a; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
			continue;
		}
	}

	for (int i = 0; i < a; i++)
	{
		printf("%c", str[i]);
	}
}



void main()
{
	char str[50];
	char ch;

	printf("문자열을 입력하세요 : ");
	gets(str);

	printf("지울 문자를 입력하세요 : ");
	scanf("%c", &ch);

	printf("%c를 삭제한 후\n", ch);

	delchar(str, ch);
}