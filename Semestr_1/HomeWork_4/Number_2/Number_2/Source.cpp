#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include "Head_MyFuncSem_1.h"

int main()
{
	FILE *file = fopen("FileForNumber_2.txt", "r");
	if (!file) 
	{
		printf("File not found!");
		return 1;
	}




	fclose(file);
	return 0;
}
