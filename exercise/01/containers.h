#pragma once
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

void remove_element(std::vector<int>& v, int index);
void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value);

int list_nth_element(const std::list<int>& c, int index);
void list_sort_desc(std::list<int>& c);

int unique_numbers(std::wistream&);

class word_frequency
{
private:
  std::multiset<std::wstring> m_stringMultiSet;
  std::set<std::wstring> m_stringSet;
public:
	word_frequency(std::wistream&); 
  void split(std::wistream& is);
	int frequency(const std::wstring& s);
	int count();
};
