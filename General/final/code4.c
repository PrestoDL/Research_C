// 2020116706 전영원

#include <stdio.h>
#include <string.h>

void main()
{
	char ch[50];
	char* s;

	printf("한줄의 문장을 입력하세요.\n-> ");
	gets(ch);

	printf("\n입력한 각각의 단어를 반대로 출력합니다.\n-> ");

	s = strtok(ch, " ");

	while (ch != NULL)
	{
		int len = strlen(s);
		for (int i = 1; i <= len; i++)
		{
			printf("%c", s[len - i]);
		}
		printf(" ");
		s = strtok(NULL, " ");
	}
}