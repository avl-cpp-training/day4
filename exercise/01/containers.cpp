#include "containers.h"
#include <iostream>
#include <set>
#include <algorithm>

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
	return  *it;
}
bool compare_int(const int& first, const int& second)
{
	return first> second;
}

void list_sort_desc(std::list<int>& c)
{
//	std::sort(c.begin(), c.end(), std::greater<int>());
	c.sort(compare_int);
}

int unique_numbers(std::wistream& is)
{
	std::set<int>  uniqueInt;
	int n;
	while (is >> n)
	{
		uniqueInt.insert(n);
	}
	return uniqueInt.size();
}

word_frequency::word_frequency(std::wistream& str)
{
	std::wstring string;
	std::list<std::wstring>::iterator it = strings.begin();
	while (str>> string)
	{
		std::transform(string.begin(), string.end(), string.begin(), ::tolower);
		strings.insert(it, string);
		if (it == strings.end()) { it = strings.begin(); }
		else { it++; }
	}
}

int word_frequency::count()
{
	std::set<std::wstring> aa;
	for (const auto string : strings)
		aa.insert(string);
	return aa.size();
}

int word_frequency::frequency(const std::wstring& s)
{
	std::wstring pero;
	std::transform(s.begin(), s.end(),std::back_inserter(pero), ::tolower);
	std::list<std::wstring>::iterator it = strings.begin();;
	int  numberOfRepat=0;
	for(it=strings.begin(); it!=strings.end();it++)
	{
		if (*it == pero)
			numberOfRepat++;
	}
	return numberOfRepat;
}


