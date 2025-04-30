// 2020116706 전영원

#include <stdio.h>

struct person
{
	char name[20];
	char tel[20];
	char address[20];
};

struct employee
{
	struct person p;
	int number;
	int sal;
	double incentive;
};


void main()
{
	struct employee a[3];


	for (int i = 0; i < 3; i++)
	{
		printf("정보를 입력하세요.\n");
		
		printf("    이름 : ");
		gets(&a[i].p.name);

		printf("전화번호 : ");
		gets(&a[i].p.tel);

		printf("    주소 : ");
		gets(&a[i].p.address);

		printf("    사번 : ");
		scanf("%d", &a[i].number);

		printf("    월급 : ");
		scanf("%d", &a[i].sal);

		printf("인센티브 : ");
		scanf("%lf", &a[i].incentive);

		puts("\n");
	}

	printf("    사번      이름            전화번호              주소        월급     인센티브      연봉\n");

	for (int i = 0; i < 3; i++)
	{
		printf("%d      %s      %s       %s       %d      %.0lf%%       %.0lf\n", a[i].number, a[i].p.name, a[i].p.tel, a[i].p.address, a[i].sal, 100 * a[i].incentive, a[i].sal * ( 12 + a[i].incentive ));
	}
}