#include "containers.h"

void remove_element(std::vector<int>& v, int index)
{
  v.erase(v.cbegin() + index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring & value)
{
  v.insert(v.cbegin() + index, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
  auto it = c.begin();
  std::advance(it, index);

  return *it;
}

void list_sort_desc(std::list<int>& c)
{
  c.sort();
  c.reverse();
}

int unique_numbers(std::wistream& is)
{
  std::set<int> uniques;
  std::wstring temp;
  while (is >> temp)
  {
    uniques.insert(stoi(temp));
  }
  return uniques.size();
}

word_frequency::word_frequency(std::wistream & is) 
{
  split(is);
}

void word_frequency::split(std::wistream & is)
{
  std::wstring temp;
  while (is >> temp)
  {
    std::transform(temp.begin(), temp.end(), temp.begin(), ::towlower);
    m_stringMultiSet.insert(temp);
    m_stringSet.insert(temp);
  }
}

int word_frequency::frequency(const std::wstring & s)
{
  return m_stringMultiSet.count(s);
}

int word_frequency::count()
{
  return m_stringSet.size();
}
