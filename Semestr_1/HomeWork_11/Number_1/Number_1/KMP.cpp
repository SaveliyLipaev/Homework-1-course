#include <string>
#include <fstream>

void prefixFunc(int *prefixMas, const std::string &prototype)
{
	prefixMas[0] = 0;
	for (int i = 1, j = 0; i < prototype.length();)
	{
		if (prototype[i] == prototype[j])
		{
			prefixMas[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0)
		{
			prefixMas[i] = 0;
			i++;
		}
		else
		{
			j = prefixMas[j - 1];
		}
	}
}

int find(std::ifstream &file, const std::string &prototype)
{
	int *prefixMas = new int[prototype.length()];
	prefixFunc(prefixMas, prototype);
	int counter = 0;
	while (!file.eof())
	{
		std::string buffer;
		getline(file, buffer);
		int i = 0;
		int j = 0;
		while (true)
		{
			if (buffer[i] == prototype[j])
			{
				++i;
				++j;
				if (j == prototype.length())
				{
					delete[] prefixMas;
					return counter + i + 1 - prototype.length();
				}
				else if (i == buffer.length())
				{
					break;
				}
			}
			else if (j == 0)
			{
				++i;
				if (i == buffer.length())
				{
					break;
				}
			}
			else
			{
				j = prefixMas[j - 1];
			}
		}
		counter += buffer.length();
	}
	delete[] prefixMas;
	return -1;
}