// 2020116706 Àü¿µ¿ø

#include <stdio.h>

void main()
{
	int a;
	int f;

	int i = 2;
	int div;
	int line = 0;

	for (f = 1; f <= 10; f++)
	{
		for (a = 1; a <= 10 - f; a++)
		{
			printf("  ");
		}

		while(i)
		{
			for (div = 2; i % div; div++);
			{
				if (div == i)
				{
					printf("%3d ", i);
					line++;
				}
			}
			i++;

			if (f == line)
			{
				printf("\n");
				line = 0;
				break;
			}
		}
	}
}