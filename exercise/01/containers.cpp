#include "containers.h"
#include <set>
#include <locale>
#include <cwctype>

void remove_element(std::vector<int>& v, int index)
{
  v.erase(v.begin() + index);
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
  int n;
  std::set<int> uniqueNumbers;

  while (s >> n)
  {
    uniqueNumbers.insert(n);
  }

  return uniqueNumbers.size();
}

word_frequency::word_frequency(std::wistream& stream)
{
  std::wstring s;
  while (stream >> s)
  {
    ToLower(s);
    if (data.find(s) != data.end())
    {
      data[s]++;
    }
    else
    {
      data[s] = 1;
    }
  }
}

int word_frequency::frequency(const std::wstring& s)
{
  if (data.find(s) != data.end())
  {
    return data[s];
  }

  return 0;
}

int word_frequency::count()
{
  return data.size();
}

void word_frequency::ToLower(std::wstring& str)
{
  for(wchar_t& c : str)
  {
    c= std::towlower(c);
  }
}
