/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//2020116706

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int inputcheck(int arr[])
{
    char full[100];
    printf("input 10 integers in ascending order > ");
    gets(full);

    int i = 0;
    char* temp = strtok(full, " ");

    while (temp != NULL && i < 10)
    {
        arr[i] = atoi(temp);
        temp = strtok(NULL, ", ");
        i++;
    }

    if (temp == NULL && i == 10)
    {
        for (int c = 0; c < 10 - 1; c++)
        {
            if (arr[c] > arr[c + 1])
            {
                printf("The input numbers are not in ascending order.");
                return 2;
            }
        }

        return 0;
    }

    else
    {
        printf("You should input 2 sets of 10 numbers.");
        return 1;
    }
}

int descsum(int arr1[], int arr2[], int sum[])
{
    int counta = 10; int countb = 10;

    for (int i = 0; i < 20; i++)
    {
        if (counta == 0)
        {
            sum[i] = arr2[countb - 1];
            countb--;
        }

        else if (countb == 0)
        {
            sum[i] = arr1[counta - 1];
            counta--;
        }

        else
        {
            if (arr1[counta - 1] < arr2[countb - 1])
            {
                sum[i] = arr2[countb - 1];
                countb--;
            }

            else
            {
                sum[i] = arr1[counta - 1];
                counta--;
            }
        }
    }

    int size = 20;

    for (int i = 0; i < size - 1; i++)
    {
        if (sum[i] == sum[i + 1])
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                sum[j] = sum[j + 1];
            }
            sum[size - 1] = NULL;
            size--;
            i--;
        }
    }

    return size;
}

int main()
{
    int sum[20];
    
    int a[10]; int b[10];
    if (inputcheck(a) == 0 && inputcheck(b) == 0)
    {
        int s = descsum(a, b, sum);

        for (int i = 0; i < s; i++)
        {
            printf("%d ", sum[i]);
        }
    }

    return 0;
}