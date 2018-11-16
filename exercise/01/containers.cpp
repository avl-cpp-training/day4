#include "containers.h"
#include <iterator>

void remove_element(std::vector<int>& v, int index)
{
	auto it = v.begin();
	std::advance(it, index);
	v.erase(it);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value)
{
	auto it = v.begin();
	std::advance(it, index);
	v.insert(it, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
	auto it = c.begin();
	std::advance(it, index);

	return *it;
}

void list_sort_desc(std::list<int>& c)
{
	for (auto it = c.begin(); it != c.end(); ++it)
	{
		for (auto it2 = c.begin()++; it2 != c.end(); ++it2)
		{
			if (*it > *it2)
			{
				auto temp = *it;
				*it = *it2;
				*it2 = temp;
			}
		}
	}
}

int unique_numbers(std::wistream& is)
{
	std::vector<int> uniqueNumbers;

	int n;
	while (is >> n)
	{
		bool unique = true;

		for (int i = 0; i  < uniqueNumbers.size(); i++)
		{
			if (uniqueNumbers[i] == n)
			{
				unique = false;
				break;
			}
		}

		if (unique)
		{
			uniqueNumbers.push_back(n);
		}
	}

	return uniqueNumbers.size();
}

word_frequency::word_frequency(std::wistream& in)
{
	std::wstring word;

	while (in >> word)
	{
		for (wchar_t& c:word)
		{
			c = towlower(c);
		}
		words.push_back(word);
	}
}

int word_frequency::frequency(const std::wstring& s)
{
	int count = 0;

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i]._Equal(s))
		{
			count++;
		}
	}

	return count;
}

int word_frequency::count()
{
	std::vector<std::wstring> uniqueWords;

	for (int i = 0; i < words.size(); i++)
	{
		bool unique = true;

		for (int j = 0; j < uniqueWords.size(); j++)
		{
			if (words[i]._Equal(uniqueWords[j]))
			{
				unique = false;
				break;
			}
		}

		if (unique)
		{
			uniqueWords.push_back(words[i]);
		}
	}

	return uniqueWords.size();
}
