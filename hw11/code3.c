// 2020116706 전영원

#include <stdio.h>

int total = 0;

void deposit(int money);
void withdraw(int money);

void main()
{
    int n;
    static int amount;

    do {
        printf("\n원하는 메뉴를 선택하세요.\n");
        printf("(1)잔고확인   (2)입금   (3)출금   (4)종료\n");
        printf("메뉴 선택 : ");

        scanf("%d", &n);

        if (n == 1)
        {
            printf("현재 잔고는 %d원 입니다.\n", total);
        }

        if (n == 2)
        {
            printf("입금액을 입력하세요 : ");
            scanf("%d", &amount);
            deposit(amount);
        }

        if (n == 3)
        {
            printf("출금액을 입력하세요 : ");
            scanf("%d", &amount);
            withdraw(amount);
        }

        if (n == 4)
        {
            printf("종료되었습니다.\n");
            break;
        }

    } while (1);

    return 0;
}



void deposit(int money)
{
    total += money;
}
void withdraw(int money)
{
    if (total >= money)
    {
        total -= money;
    }

    else
    {
        printf("잔액이 부족합니다\n");
    }
}