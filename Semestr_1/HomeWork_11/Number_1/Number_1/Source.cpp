#include <iostream>
#include "KMP.h"
#include "test.h"

int main()
{
	if (!test())
	{
		std::cout << "Test failed\n";
		return 1;
	}

	std::ifstream file("text.txt");
	std::string findString;

	std::cout << "Enter the string you want to find in the file\n";
	getline(std::cin, findString);

	int venue = KnutMorrisPrattForFile(file, findString);

	if (venue == -1)
	{
		std::cout << "\nThere is no such line in the file\n";
	}
	else
	{
		std::cout << "\nThe entered line is found in the file on " << venue << " place\n";
	}

	file.close();
	return 0;
}