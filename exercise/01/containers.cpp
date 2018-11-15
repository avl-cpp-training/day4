#include "containers.h"
#include <list>
#include <set>
#include <map>
#include <iterator>

void remove_element(std::vector<int>& v, int index)
{
	v.erase(v.begin() + 2);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value)
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

int unique_numbers(std::wistream& s)
{
	std::wstring number;
	std::set<std::wstring> wstring_set;
	while (s >> number)
	{
		wstring_set.insert(number);
	}

	return wstring_set.size();
}

word_frequency::word_frequency(std::wistream& stream)
{
	std::wstring s;
	while (stream >> s)
	{
		s = wchar_t(tolower(s[0])) + s.substr(1);
		map[s] = ++map[s];
	}		
}

int word_frequency::frequency(const std::wstring& s)
{
	if (map.find(s) == map.end())
		return 0;

	return map[s];
}

int word_frequency::count()
{
	return map.size();
}

