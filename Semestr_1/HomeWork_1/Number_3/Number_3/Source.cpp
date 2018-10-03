#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void v_obratku(int *m, int amount);
int main() {
	int m, n, i;
	printf("Enter m and n\n");
	scanf("%d%d", &m, &n);
	int* mas = new int[m + n];

	for (i = 0; i < m + n; ++i)
		scanf("%d", &mas[i]);

	v_obratku(mas, m);
	v_obratku(&mas[m], n);
	v_obratku(mas, m + n);

	for (i = 0; i < n + m; ++i)
		printf("%d ", mas[i]);
	printf("\n");

	delete[] mas;
	return 0;
}
void v_obratku(int *m, int amount) {
	for (int j = 0; j < amount / 2; ++j)
	{
		int help_peremen = m[amount - j - 1];
		m[amount - j - 1] = m[j];
		m[j] = help_peremen;
	}
}