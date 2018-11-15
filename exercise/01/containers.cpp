#include "containers.h"
#include <unordered_set>
#include <sstream>
//#include <algorithm>

void remove_element(std::vector<int>& v, int index)
{
	v.erase(v.begin()+index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value)
{
	v.insert(v.begin() + index, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
	auto it = c.begin();
	std::advance(it, index);
	return it != c.end() ? *it : 0;
}

void list_sort_desc(std::list<int>& c)
{
	c.sort(std::greater<int>());
}

int unique_numbers(std::wistream& wis)
{
	std::unordered_set<int> s;
	int n;
	while (wis >> n)
		s.insert(n);
	return s.size();
}

namespace
{
	std::wstring to_lower(const std::wstring& wstr)
	{
		std::wstring w(wstr);
		for (wchar_t& wc : w)
			 wc = ::towlower(wc);
		//std::transform(w.begin(), w.end(), w.begin(), ::towlower);
		return w;
	}
}

word_frequency::word_frequency(std::wistream& wis)
{
	std::wstring w;
	while (wis >> w)
		word_freq[to_lower(w)]++;
}

int word_frequency::frequency(const std::wstring & s)
{
	auto ws = to_lower(s);
	return word_freq.find(ws) != word_freq.end() ? word_freq[ws] : 0;
}

int word_frequency::count()
{
	return word_freq.size();
}
