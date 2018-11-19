#include <vector>
#include "stackFor9.1.h"
#include "HashTable.h"

using namespace std;

struct Set
{
	vector<Stack> buckets;
};

void constructor(Set &set)
{
	int size = 1000;
	set.buckets.resize(size);
}

long long hashFunction(const string &str)
{
	int prime = 53;
	long long sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum += prime * str[i];
		prime *= prime;
	}
	return sum;
}

void add(Set &set, const string str)
{
	const int hash = hashFunction(str) % set.buckets.size();
	NodeStack *node = findNode(&set.buckets[hash], str);
	if (node == nullptr)
	{
		push(&set.buckets[hash], str);
	}
	else
	{
		++node->quantity;
	}
}