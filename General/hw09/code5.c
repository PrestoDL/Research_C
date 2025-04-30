// 2020116706 전영원

#include <stdio.h>

void copyarray(int from[], int to[], int n)
{
	for (int i = 0; i < n; i++)
	{
		to[i] = from[i];
	}
}

int isequalarray(int arr1[], int arr2[], int n)
{
	int s = 0;

	if (sizeof(arr1) == sizeof(arr2))
	{
		for (int i = 0; i < n; i++)
		{
			if (arr1[i] == arr2[i])
			{
				s++;
			}
		}

		if (s == n)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	else
	{
		return 0;
	}
}



void main()
{
	int a[] = { 4, 7, 9, 3, 6 };
	int b[] = { 10, 20, 30, 40, 50 };

	printf("\na -> ");
	for (int i = 0; i < 5; i++)
	{
		printf("%3d", a[i]);
	}

	printf("\nb -> ");
	for (int i = 0; i < 5; i++)
	{
		printf("%3d", b[i]);
	}


	copyarray(a, b, 5);

	printf("\n\n복사 후 배열 b는");
	printf("\nb -> ");
	for (int i = 0; i < 5; i++)
	{
		printf("%3d", b[i]);
	}


	if (isequalarray(a, b, 5))
	{
		printf("\n\n--배열 a와 b는 같다--\n\n");
	}

	else
	{
		printf("\n\n--배열 a와 b는 같지 않다--\n\n");
	}
}