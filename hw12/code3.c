// 2020116706 전영원

#include <stdio.h>

struct person
{
	char name[10];
	char tel[15];
	char address[20];
};

struct employee
{
	struct person p;
	int number;
	float sal;
	double incentive;
};



void main()
{
	struct employee a[3];

	for (int i = 0; i < 3; i++)
	{
		puts("정보를 입력하세요.\n");

		printf("    이름 : ");
		scanf("%s", &a[i].p.name);

		printf("전화번호 : ");
		scanf("%s", &a[i].p.tel);

		printf("    주소 : ");
		scanf("%s", &a[i].p.address);

		printf("    사번 : ");
		scanf("%d", &a[i].number);

		printf("    월급 : ");
		scanf("%f", &a[i].sal);

		printf("인센티브 : ");
		scanf("%lf", &a[i].incentive);

		puts("\n");
	}
	puts("\n      사번      이름      전화번호           주소         월급     인센티브          연봉");
	for (int i = 0; i < 3; i++)
	{
		printf("%8d    %s   %s     %10s   %10.0f         %4.0lf%%   %10.0lf\n", a[i].number, a[i].p.name, a[i].p.tel, a[i].p.address, a[i].sal, a[i].incentive * 100, a[i].sal * (12 + a[i].incentive));
	}
}