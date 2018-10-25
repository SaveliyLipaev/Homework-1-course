#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funcFor4.1.h"

void translationIntoAdditionalCode(const int number, bool* mas)
{
	unsigned int bit = 0b01000000000000000000000000000000;
	mas[0] = (number < 0);
	for (int i = 1; i < sizeof(int) * 8; ++i)
	{
		mas[i] = (number & bit);
		bit = bit >> 1;
	}
}

void printBinary(bool *binary)
{
	for (int i = 0; i < sizeof(int) * 8; ++i)
	{
		printf("%d", binary[i]);
	}
	printf("\n");
}

void sumAdditionalCode(bool* first, bool* second, bool* sum)
{
	bool helpVeriable = 0;
	for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		switch (first[i] + second[i] + helpVeriable)
		{
		case 0:
		{
			sum[i] = 0;
			helpVeriable = 0;
			break;
		}
		case 1:
		{
			sum[i] = 1;
			helpVeriable = 0;
			break;
		}
		case 2:
		{
			sum[i] = 0;
			helpVeriable = 1;
			break;
		}
		case 3:
		{
			sum[i] = 1;
			helpVeriable = 1;
			break;
		}
		}
	}
}

int translationIntoDecimal(bool* mas)
{
	int number = 0;
	unsigned int helpVeriable = 1;

	for (int i = sizeof(int) * 8 - 1; i > 0; i--)
	{
		if (mas[i] ^ mas[0])
		{
			number += helpVeriable;
		}
		helpVeriable *= 2;
	}
	if (mas[0] == 1)
	{
		return -number - 1;
	}
	return number;
}