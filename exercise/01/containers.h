#pragma once
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cwctype>


void remove_element(std::vector<int>& v, int index);
void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value);

int list_nth_element(const std::list<int>& c, int index);
void list_sort_desc(std::list<int>& c);

int unique_numbers(std::wistream&);
void CastToLower(std::wstring& word);

class word_frequency
{
public:
  word_frequency() = default;
	word_frequency(std::wistream& stream);
  int frequency(const std::wstring& word);
	int count();

private:
  std::map<std::wstring, int> m_Words;
};
