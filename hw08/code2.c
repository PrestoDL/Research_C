//2020116706 전영원

#include <stdio.h>

#define i 5
#define j 5

void main()
{
	int chart[i][j];
	chart[0][0] = 78; chart[0][1] = 48; chart[0][2] = 78; chart[0][3] = 98; chart[0][4] = 0;
	chart[1][0] = 99; chart[1][1] = 92; chart[1][2] = 83; chart[1][3] = 29; chart[1][4] = 0;
	chart[2][0] = 29; chart[2][1] = 64; chart[2][2] = 83; chart[2][3] = 89; chart[2][4] = 0;
	chart[3][0] = 34; chart[3][1] = 78; chart[3][2] = 92; chart[3][3] = 56; chart[3][4] = 0;
	chart[4][0] = 0;  chart[4][1] = 0;  chart[4][2] = 0;  chart[4][3] = 0;  chart[4][4] = 0;

	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			printf("%5d", chart[a][b]);
		}
		printf("\n");
	}

	printf("\n위 행렬의 세로와 가로합, 그리고 모든 합을 각각 행과 열의 마지막에 구합니다.\n\n");

	for (int c = 0; c < 4; c++)
	{
		for (int d = 0; d < 4; d++)
		{
			chart[c][4] += chart[c][d];
		}
	}

	for (int e = 0; e < 4; e++)
	{
		for (int f = 0; f < 4; f++)
		{
			chart[4][e] += chart[f][e];
		}
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			chart[4][4] += chart[x][y];
		}
	}

	for (int a = 0; a < i; a++)
	{
		for (int b = 0; b < j; b++)
		{
			printf("%5d", chart[a][b]);
		}
		printf("\n");
	}
}