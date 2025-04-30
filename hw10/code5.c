//2020116706 전영원

#include <stdio.h>
#include <ctype.h>

void reverse(char* pt)
{
	int l = strlen(pt);

	puts("\n/입력한 단어의 대소문자를 바꿉니다.");

	for (int i = 0; i < l; i++)
	{
		if (isalpha(pt[i]) == 1)
		{
			pt[i] = tolower(pt[i]);
		}

		else if (isalpha(pt[i]) == 2)
		{
			pt[i] = toupper(pt[i]);
		}
	}
}



void main()
{
	char a[100];

	puts("/영문문장을 입력하세요.");
	printf("-> ");
	gets(a);

	reverse(a);

	printf("-> ");
	puts(a);
}