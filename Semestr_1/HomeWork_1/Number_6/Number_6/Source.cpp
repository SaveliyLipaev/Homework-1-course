#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>

int main() {
	char S[] = "abscdekfmgcde", S1[] = "cde";
	int counter = 0;
	for (int i = 0; i <= strlen(S) - strlen(S1); ++i)
	{
		if (strncmp(&S[i], S1, strlen(S1)) == 0)
		{
			++counter;
		}
	}
	printf("Number of occurrences of S1 in S as substrings = %d\n", counter);
	return 0;
}