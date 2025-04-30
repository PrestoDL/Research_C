// 2020116706 Àü¿µ¿ø

#include <stdio.h>

struct date
{
	int year;
	int month;
	int day;
};

struct movie
{
	char title[16];
	char direct[16];
	int watch;
	struct date p;
};



void main()
{
	struct movie a[4] =
	{
		{ "¸í·®", "±èÇÑ¹Î", 17613000, {2014, 7, 30} },
		{ "µµµÏµé", "ÃÖµ¿ÈÆ", 12983000, {2014, 12, 17} },
		{ "±¹Á¦½ÃÀå", "À±Á¦±Õ", 14257000, {2014, 12, 17} },
		{ "º£Å×¶û", "À¯½Â¿Ï", 13383000, {2015, 8, 5} }
	};

	puts("   Á¦¸ñ      °¨µ¶    °ü°´¼ö     °³ºÀÀÏ");
	puts("========================================");

	for (int i = 0; i < 4; i++)
	{
		printf("[%8s]  %6s  %d  %4d.%2d.%2d\n", a[i].title, a[i].direct, a[i].watch, a[i].p.year, a[i].p.month, a[i].p.day);
	}
}