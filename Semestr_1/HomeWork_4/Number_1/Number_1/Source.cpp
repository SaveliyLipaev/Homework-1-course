#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <clocale>
#include "funcFor4.1.h"

int main() 
{
	setlocale(LC_ALL, "Russian");

	int firstNumber = 0;
	int secondNumber = 0;

	bool buffer1[bitInt]{};
	bool buffer2[bitInt]{};
	bool sum[bitInt]{};

	printf("Введите 2 числа: \n");
	scanf("%d%d", &firstNumber, &secondNumber);

	translationIntoAdditionalCode(firstNumber, buffer1);
	translationIntoAdditionalCode(secondNumber, buffer2);

	printBinary(buffer1);
	printBinary(buffer2);

	sumAdditionalCode(buffer1, buffer2, sum);

	printBinary(sum);

	printf("Сумма в десятичном виде: %d", translationIntoDecimal(sum));

	scanf("%d", &firstNumber);
	return 0;
}

