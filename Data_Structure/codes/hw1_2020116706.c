/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//2020116706

#include <stdio.h>
#include <string.h>

int main()
{
    struct student
    {
        char fullname[50]; // 전체이름
        char* lastname; // 성을 가리키는 포인터
        char* firstname; // 이름을 가리키는 포인터
        int age;
        char sex;
    };

    
    while (1)
    {
        struct student a;
        printf("Provide your personal information :");


        printf("\n > Name : ");
        gets(a.fullname);

        if (strcmp(a.fullname, "stop") == 0)
        {
            break;
        }

        a.firstname = strtok(a.fullname, " ");
        a.lastname = strtok(NULL, " ");

        printf("\n > Age : ");
        scanf(" %d", &a.age);

        printf("\n > Sex (M/F) : ");
        scanf(" %c", &a.sex);


        printf("\nYour name is %s %s, you are in %ds, your sex is %c.", a.lastname, a.firstname, (a.age / 10) * 10, a.sex);
        printf("\n\n\n");

        getchar();
    }
    return 0;

}
