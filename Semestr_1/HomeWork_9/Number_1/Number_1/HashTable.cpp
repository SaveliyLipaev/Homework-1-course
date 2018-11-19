#include <vector>
#include "ListFor9.1.h"

struct HashTable
{
	int maxLengthList = 0;
	int amountOfElements = 0;
	std::vector<List*> buckets;
};

void constructor(HashTable &table)
{
	int size = 900;
	table.buckets.resize(size);
}

unsigned long long hashFunction(const std::string &str)
{
	unsigned int prime = 31;
	unsigned long long sum = 0;
	for (int i = 0; i < (int)str.length(); ++i)
	{
		sum += prime * str[i];
		prime *= prime;
	}
	return sum;
}

void add(HashTable &table, const std::string str)
{
	++table.amountOfElements;

	const int hash = hashFunction(str) % table.buckets.size();

	NodeList *node = findNode(table.buckets[hash], str);

	if (node == nullptr)
	{
		push(table.buckets[hash], str);
	}
	else
	{
		increaseQuantity(node);
	}

	if (lengthList(table.buckets[hash]) > table.maxLengthList)
	{
		table.maxLengthList = lengthList(table.buckets[hash]);
	}
}

void printTable(HashTable &table)
{
	for (int i = 0; i < (int)table.buckets.size(); ++i)
	{
		printlist(table.buckets[i]);
	}
}

HashTable* createHashTable()
{
	return new HashTable;
}

float loadFactor(HashTable &table)
{
	return (float)table.amountOfElements / (float)table.buckets.size();
}

void deleteHashTable(HashTable &table)
{
	for (int i = 0; i < (int)table.buckets.size(); ++i)
	{
		deleteList(table.buckets[i]);
	}
	delete &table;
}

int maxLength(HashTable &table)
{
	return table.maxLengthList;
}

float averageLength(HashTable &table)
{
	int sum = 0;
	for (int i = 0; i < (int)table.buckets.size(); ++i)
	{
		sum += lengthList(table.buckets[i]);
	}
	return (float)sum / (float)table.buckets.size();
}