//2020116706 전영원

#include <stdio.h>
#include <string.h>

void mystrcat(char s1[], char s2[])
{
	int a = strlen(s1);
	int b = strlen(s2);

	for (int i = 0; i < b; i++)
	{
		s1[a + i] = s2[i];
	}

	s1[a + b] = '\0';
}



void main()
{
	char p[50];
	char q[50];

	printf("앞 문자열을 입력하세요 : ");
	gets(p);
	printf("뒤 문자열을 입력하세요 : ");
	gets(q);

	mystrcat(p, q);

	printf("연결된 결과 (mystrcat) : %s\n\n\n", p);


	char r[50];
	char s[50];

	printf("앞 문자열을 입력하세요 : ");
	gets(r);
	printf("뒤 문자열을 입력하세요 : ");
	gets(s);

	printf("연결된 결과  (strcat)  : %s\n", strcat(r, s));
}