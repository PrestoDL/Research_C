// 2020116706 Àü¿µ¿ø

#include <stdio.h>

void main()
{
	int i;
	int line = 1;

	for (i = 1; i <= 100; i++)
	{
		if (i % 2 && i % 3 && i % 5 && i % 7)
		{
			printf("%d%c", i, (line++ % 10) ? ' ' : '\n');
		}
	}
}