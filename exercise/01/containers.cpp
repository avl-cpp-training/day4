#include "containers.h"
#include <set>
#include <iostream>

void remove_element(std::vector<int>& v, int index)
{
	v.erase(v.begin() + index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring & value)
{
	v.insert(v.begin() + index, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
	std::list<int>::const_iterator it = c.begin();
	std::advance(it, index);
	return *it;
}

void list_sort_desc(std::list<int>& c)
{
	c.sort();
	c.reverse();
}

int unique_numbers(std::wistream& stream)
{
	int n;
	std::set<int> my_set;
	while (stream >> n)
		my_set.insert(n);
	return my_set.size();
}

word_frequency::word_frequency(std::wistream & ss)
{
	std::wstring word;
	while (ss >> word)
	{
		to_lower(word);
		++map_of_words[word];
	}
}

int word_frequency::frequency(const std::wstring & s)
{
	auto it = map_of_words.find(s);
	if (it != map_of_words.end())
		return (*it).second;
	return int();
}

int word_frequency::count()
{
	return map_of_words.size();
}

void word_frequency::to_lower(std::wstring & word) const
{
	for (std::wstring::iterator it = word.begin(); it != word.end(); ++it)
		*it = towlower(*it);
}
