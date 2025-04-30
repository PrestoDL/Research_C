// 2020116706 전영원

#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    puts("한줄의 문장을 입력하세요. ->");
    gets(a);

    char* pt = strtok(a, " ");

    printf("\n입력한 각각의 단어를 반대로 출력합니다. ->\n");

    while (pt != NULL)
    {
        for (int i = strlen(pt) - 1; i > -1; i--)
        {
            printf("%c", pt[i]);
        }
        printf(" ");
        pt = strtok(NULL, " ");
    }
    printf("\n");
}