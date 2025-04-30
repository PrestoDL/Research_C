//2020116706 전영원

#include <stdio.h>

void main()
{
	int value = 0x2F24263F;

	char* pc = (char*)&value;

	printf("변수명   저장값        주소값\n");
	printf("-----------------------------\n");
	printf("value    %0#x   %p\n", value, pc);

	for (int i = 0; i < 4; i++)
	{
		char ch = *(pc + i);
		printf("*(pc+%d)  %0#4x   %2c    %p\n", i, ch, ch, pc + i);
	}
}