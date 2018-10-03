#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>

int main() {
	char stroka[] = "(())()()(())";
	int balanc = 0;
	for (int i = 0; i < strlen(stroka); ++i)
	{
		if (stroka[i] == ')')
		{
			--balanc;
		}
		else
		{
			++balanc;
		}
		if (balanc < 0)
		{
			break;
		}
	}
	if (balanc == 0)
	{
		printf("Balance is observed!!!\n");
	}
	else
	{
		printf("Upss, the balance is not met :(\n");
	}
	return 0;
}