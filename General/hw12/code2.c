// 2020116706 전영원

#include <stdio.h>

struct person
{
	char name[18];
	char tel[15];
	char address[20];
};

union reg
{
	struct person p;
	char company[20];
};

struct car
{
	int year;
	int month;
	char vehicle[10];
	union reg owner;
};



void main()
{
	struct car a = { 2004, 9, "그랜져GT", {{"홍길동", "011-1111-1111", "서울시구로구고척동"}} };
	struct car b = { 2006, 4, "인피니티", "인피니티북스" };

	puts("  년 식      종류                    주인");
	puts("===============================================================");

	printf("%d %02d    %s    %s %s %s\n", a.year, a.month, a.vehicle, a.owner.p.name, a.owner.p.tel, a.owner.p.address);
	printf("%d %02d    %s              %s\n", b.year, b.month, b.vehicle, b.owner.company);
}