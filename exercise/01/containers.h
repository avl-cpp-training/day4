#pragma once
#include <string>
#include <vector>
#include <list>
#include <map>

void remove_element(std::vector<int>& v, int index);
void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value);

int list_nth_element(const std::list<int>& c, int index);
void list_sort_desc(std::list<int>& c);

int unique_numbers(std::wistream&);

class word_frequency
{
	std::map<std::wstring, int> word_freq;
public:
	word_frequency(std::wistream&);
	int frequency(const std::wstring& s);
	int count();
};
