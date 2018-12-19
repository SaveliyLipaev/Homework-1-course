#include <vector>

struct Sets
{
	std::vector<int> parent;
	std::vector<int> rank;
};

Sets* createSets(const int newSize)
{
	auto set = new Sets;
	set->parent.resize(newSize + 1);
	set->rank.resize(newSize + 1);
	return set;
}

void makeSet(Sets *set, const int number)
{
	set->parent[number] = number;
	set->rank[number] = 0;
}

int find(Sets *set, const int number)
{
	if (number != set->parent[number])
	{
		set->parent[number] = find(set, set->parent[number]);
	}
	return set->parent[number];
}

void unionSet(Sets *set, const int firstNumber, const int secondNumber)
{
	int firstNumberId = find(set, firstNumber);
	int secondNumberId = find(set, secondNumber);
	if (firstNumberId == secondNumberId)
	{
		return;
	}
	if (set->rank[firstNumberId] > set->rank[secondNumberId])
	{
		set->parent[secondNumberId] = firstNumberId;
	}
	else
	{
		set->parent[firstNumberId] = secondNumberId;
		if (set->rank[firstNumberId] == set->rank[secondNumberId])
		{
			++set->rank[secondNumberId];
		}
	}
}
