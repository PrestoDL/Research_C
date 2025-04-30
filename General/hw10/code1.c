//2020116706 전영원

#include <stdio.h>
#include <string.h>

int mystrlen(char* p)
{
	int a = 0;

	while (*p)
	{
		p++;
		a++;
	}

	return a;
}



void main()
{
	char c[50];

	printf("문자열을 입력하세요 : ");
	gets(c);

	printf("입력한 문자열은 : ");
	puts(c);

	printf("입력된 문자열의 길이는 : %d (mystrlen 사용)\n", mystrlen(c));
	printf("입력된 문자열의 길이는 : %d (strlen 사용)\n", strlen(c));
}