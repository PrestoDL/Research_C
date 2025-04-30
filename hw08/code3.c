//2020116706 Àü¿µ¿ø

#include <stdio.h>

void main()
{
	int a[3][2];
	int b[2][3];
	int c[3][3];

	a[0][0] = 3; a[0][1] = 5;
	a[1][0] = 4; a[1][1] = 2;
	a[2][0] = 5; a[2][1] = 7;

	b[0][0] = 3; b[0][1] = 8; b[0][2] = 2;
	b[1][0] = 2; b[1][1] = 4; b[1][2] = 6;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
		}
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			printf("%3d", c[x][y]);
		}
		printf("\n");
	}
}