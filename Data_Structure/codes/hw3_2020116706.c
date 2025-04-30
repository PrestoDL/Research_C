//2020116706

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
	char name[20];
	int age;
	int math;
	int eng;
	int his;
} id;

int file(id** lists, int *count)
{
	char filename[30];
	printf("\nFile name : ");
	gets(filename);
	FILE* p = fopen(filename, "r");
	if (p != NULL)
	{
		char line[50];
		while (fgets(line, sizeof(line), p))
		{
			strcpy((*lists)[*count].name, strtok(line, " "));
			(*lists)[*count].age = atoi(strtok(NULL, " "));
			(*lists)[*count].math = atoi(strtok(NULL, " "));
			(*lists)[*count].eng = atoi(strtok(NULL, " "));
			(*lists)[*count].his = atoi(strtok(NULL, " "));

			if ((*lists)[*count].age <= 0)
			{
				printf("The age cannot be a negative number. Program terminates.\n\n");
			}
			else if ((*lists)[*count].math < 0 || (*lists)[*count].math > 100 || (*lists)[*count].eng < 0 || (*lists)[*count].eng > 100 || (*lists)[*count].his < 0 || (*lists)[*count].his > 100)
			{
				printf("The range of score is 0 ~ 100. Program terminates.\n\n");
			}
			else
			{
				*lists = (id*)realloc(*lists, sizeof(id) * (++*count + 1));
				printf("\n");
			}
		}
		fclose(p);
		printf("\n NO.     Name      Age     Math  English  History\n\n");
		for (int i = 0; i < *count; i++)
		{
			printf(" %2d. %8s %8d %8d %8d %8d\n\n", i + 1, (*lists)[i].name, (*lists)[i].age, (*lists)[i].math, (*lists)[i].eng, (*lists)[i].his);
		}
	}
	else
	{
		printf("There is no file named '%s'. Program terminates.\n\n", filename);
	}
	return 0;
}



int main()
{
	int count = 0;
	id* lists;
	lists = (id*)malloc(sizeof(id) * (count + 1));

	int sel;
	int sor;
	while (1)
	{
		printf("\n1) Insert\n2) Sort\n3) Quit\nSelect a menu : ");
		scanf("%d", &sel);
		getchar();
		switch (sel)
		{
		case 1:
			file(&lists, &count);
			break;

		case 2:
			if (count != 0)
			{
				printf("\n\n1) Name\n2) Age\n3) Math\n4) English\n5) History\nField to sort by : ");
				scanf("%d", &sor);
				getchar();

				switch (sor)
				{
				case 1:
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = 0; j < count - 1 - i; j++)
						{
							if (strcmp(lists[j].name, lists[j + 1].name) == 1)
							{
								id temp;
								temp = lists[j];
								lists[j] = lists[j + 1];
								lists[j + 1] = temp;
							}
						}
					}

					printf("\n NO.     Name      Age     Math  English  History\n\n");
					for (int i = 0; i < count; i++)
					{
						printf(" %2d. %8s %8d %8d %8d %8d\n\n", i + 1, lists[i].name, lists[i].age, lists[i].math, lists[i].eng, lists[i].his);
					}
					break;

				case 2:
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = 0; j < count - 1 - i; j++)
						{
							if (lists[j].age > lists[j + 1].age)
							{
								id temp;
								temp = lists[j];
								lists[j] = lists[j + 1];
								lists[j + 1] = temp;
							}
						}
					}

					printf("\n NO.      Age     Name     Math  English  History\n\n");
					for (int i = 0; i < count; i++)
					{
						printf(" %2d. %8d %8s %8d %8d %8d\n\n", i + 1, lists[i].age, lists[i].name, lists[i].math, lists[i].eng, lists[i].his);
					}
					break;

				case 3:
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = 0; j < count - 1 - i; j++)
						{
							if (lists[j].math > lists[j + 1].math)
							{
								id temp;
								temp = lists[j];
								lists[j] = lists[j + 1];
								lists[j + 1] = temp;
							}
						}
					}

					printf("\n NO.     Math     Name      Age  English  History\n\n");
					for (int i = 0; i < count; i++)
					{
						printf(" %2d. %8d %8s %8d %8d %8d\n\n", i + 1, lists[i].math, lists[i].name, lists[i].age, lists[i].eng, lists[i].his);
					}
					break;

				case 4:
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = 0; j < count - 1 - i; j++)
						{
							if (lists[j].eng > lists[j + 1].eng)
							{
								id temp;
								temp = lists[j];
								lists[j] = lists[j + 1];
								lists[j + 1] = temp;
							}
						}
					}

					printf("\n NO.  English     Name      Age     Math  History\n\n");
					for (int i = 0; i < count; i++)
					{
						printf(" %2d. %8d %8s %8d %8d %8d\n\n", i + 1, lists[i].eng, lists[i].name, lists[i].age, lists[i].math, lists[i].his);
					}
					break;

				case 5:
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = 0; j < count - 1 - i; j++)
						{
							if (lists[j].his > lists[j + 1].his)
							{
								id temp;
								temp = lists[j];
								lists[j] = lists[j + 1];
								lists[j + 1] = temp;
							}
						}
					}

					printf("\n NO.  History     Name      Age     Math  English\n\n");
					for (int i = 0; i < count; i++)
					{
						printf(" %2d. %8d %8s %8d %8d %8d\n\n", i + 1, lists[i].his, lists[i].name, lists[i].age, lists[i].math, lists[i].eng);
					}
					break;

				default:
					printf("Wrong Input\n\n");
				}
			}
			else
			{
				printf("There is no data to be sorted. Program terminates.\n\n");
			}
			break;

		case 3:
			free(lists);
			return 0;

		default:
			printf("Wrong Input\n\n");
		}
	}
	return  0;
}