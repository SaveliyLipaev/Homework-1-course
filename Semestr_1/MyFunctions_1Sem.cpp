
void bubble(int *mas, const int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = length - 1; j > i; --j)
		{
			if (mas[j] < mas[j - 1])
			{
				const int buffer = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = buffer;
			}
		}
	}
}

int mostCommonElement(int *mas, const int length)
{
	heapSort(mas, length);
	return mostCommonElementInSortArray(mas, length);
}

int mostCommonElementInSortArray(int *mas, const int length)
{
	int amount = 1;
	int maxAmount = 0;
	int element = mas[0];

	for (int i = 0; i < length - 1; ++i)
	{
		if (mas[i] == mas[i + 1])
		{
			++amount;
		}
		else
		{
			if (amount > maxAmount)
			{
				maxAmount = amount;
				element = mas[i];
			}
			amount = 1;
		}
	}

	if (amount > maxAmount)
	{
		maxAmount = amount;
		element = mas[length - 1];
	}

	return element;
}

bool binSearch(int* mas, const int left, const int right, const int searchVeriable)
{
	const unsigned int average = (right + left) / 2;

	if (left >= right)
	{
		if (mas[left] == searchVeriable)
		{
			return true;
		}
		return false;
	}

	if (mas[average] == searchVeriable)
	{
		return true;
	}

	if (mas[average] > searchVeriable)
	{
		return binSearch(mas, left, average - 1, searchVeriable);
	}

	if (mas[average] < searchVeriable)
	{
		return binSearch(mas, average + 1, right, searchVeriable);
	}
}

void sortingCounting(int *mas, const int length)
{
	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < length; ++i)
	{
		if (mas[i] > max)
		{
			max = mas[i];
		}
		if (mas[i] < min)
		{
			min = mas[i];
		}
	}

	int *helpMasPos = new int[max - min + 1]{};

	for (int i = 0; i < length; ++i)
	{
		++helpMasPos[mas[i] - min];
	}

	int indexInMainArrayToFill = 0;

	for (int i = 0; i <= max - min; ++i)
	{
		for (int j = 0; j < helpMasPos[i]; ++j)
		{
			mas[indexInMainArrayToFill] = i + min;
			++indexInMainArrayToFill;
		}
	}

	delete[] helpMasPos;
}

void printMas(int *mas, const int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", mas[i]);
	}
	printf("\n");
}

void swap(int& a, int& b)
{
	const int c = a;
	a = b;
	b = c;
}

void sortingInsert(int* mas, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		for (int j = i; j > 0 && mas[j] < mas[j - 1]; --j)
		{
			swap(mas[j], mas[j - 1]);
		}
	}
}

void siftingDown(int *mas, int root, const int border)
{
	int maxChild = 0;
	bool flagPyramidShaped = false;

	while ((root * 2 + 1 <= border) && !flagPyramidShaped)
	{
		if (root * 2 + 1 == border)
		{
			maxChild = root * 2 + 1;
		}
		else
		{
			if (mas[root * 2 + 1] > mas[root * 2 + 2])
			{
				maxChild = root * 2 + 1;
			}
			else
			{
				maxChild = root * 2 + 2;
			}
		}

		if (mas[root] < mas[maxChild])
		{
			swap(mas[maxChild], mas[root]);
			root = maxChild;
		}
		else
		{
			flagPyramidShaped = true;
		}
	}
}

void heapSort(int *mas, const int length)
{
	for (int i = (length / 2) - 1; i >= 0; --i)
	{
		siftingDown(mas, i, length - 1);
	}

	for (int i = length - 1; i >= 1; --i)
	{
		swap(mas[0], mas[i]);
		siftingDown(mas, 0, i - 1);
	}
}