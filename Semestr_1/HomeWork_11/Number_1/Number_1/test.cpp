#include "KMP.h"

using namespace std;

int readAndTest(string str)
{
	ifstream file("Text.txt");
	int temp = find(file, str);
	file.close();
	return temp;
}

bool test()
{
	string str1 = "dda";
	string str2 = "fff";
	string str3 = "egj";
	return readAndTest(str1) == -1 && readAndTest(str2) == 40 && readAndTest(str3) == 17;
}