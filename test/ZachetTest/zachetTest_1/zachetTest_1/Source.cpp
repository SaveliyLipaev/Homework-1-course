#include <iostream>
#include <fstream>
#include <string>
#include "ListForSort.h"


using namespace std;

int main()
{
	ifstream readFile("Text.txt");
	auto list = createList();

	while (!readFile.eof())
	{
		string buffer;
		getline(readFile, buffer);
		for (int i = 0; i < buffer.length(); ++i)
		{
			string secondBuffer;
			for (int j = i; j < buffer.length(); ++j)
			{
				secondBuffer += buffer[j];
				auto node = findNode(list, secondBuffer);
				if (node == nullptr)
				{
					push(list, secondBuffer);
				}
			}
		}
	}
	readFile.close();
	ofstream newFile("result.txt");
	mergeSort(list);
	printListInFile(list, newFile);
	newFile.close();
	deleteList(list);
	return 0;
}