#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NUM 10
void main(void)
{
	int mass[NUM] = { -1,2,5,1,2,0,-5,1,4,7 };
	FILE *finp;
	int i, j;
	finp = fopen("test.txt","w");
	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < mass[i]; j++)
		{
			fprintf(finp, "a");
		}
		if(i!=NUM-1)
			fprintf(finp, "\n");
	}
}