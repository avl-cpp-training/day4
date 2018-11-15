#include "containers.h"
#include <set>
#include <cctype>

void remove_element(std::vector<int>& v, int index)
{
	auto it = v.cbegin();
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
	auto it = c.cbegin();
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
	std::set<int> set;

	while (stream >> n)
	{
		set.insert(n);
	}
	return set.size();
}

std::wstring to_lower(const std::wstring& s)
{
	std::wstring lower;
	for (auto it = s.cbegin(); it != s.cend(); ++it)
	{
		lower.push_back(std::tolower(*it));
	}
	return lower;
}

word_frequency::word_frequency(std::wistream& ss)
{
	std::wstring s;
	while (ss >> s)
	{
		map[to_lower(s)]++;
	}
}

int word_frequency::frequency(const std::wstring& s)
{
	auto it = map.find(to_lower(s));
	if (it != map.end())
	{
		return it->second;
	}
	return 0;
}

int word_frequency::count()
{
	return map.size();
}

