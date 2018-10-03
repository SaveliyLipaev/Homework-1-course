#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int main() {
	float znach = 0, x = 0, xv2 = 0;
	scanf("%f", &x);
	xv2 = x * x;
	znach = (xv2 + x)*(xv2 + 1) + 1;
	printf("%f\n", znach);
	return 0;
}