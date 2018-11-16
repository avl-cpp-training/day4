#include "containers.h"
#include <map>
#include <set>
#include <cwctype>

void remove_element(std::vector<int>& v, int index)
{
  if (static_cast<size_t>(index) < v.size())
    v.erase(v.begin() + index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value)
{
  v.insert(v.begin() + index, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
  if (c.size() <= static_cast<size_t>(index))
    throw std::out_of_range("index is out of range: index == " + std::to_string(index));
  auto it = c.cbegin();
  std::advance(it, index);
  return *it;
}

void list_sort_desc(std::list<int>& c)
{
  c.sort();
}

int unique_numbers(std::wistream& stream)
{
  auto set = std::set<std::wstring>();
  std::wstring str;
  while (stream >> str)
    set.insert(str);
  return set.size();
}

word_frequency::word_frequency(std::wistream& stream)
{
  std::wstring str;
  while (stream >> str)
  {
    for (auto& c : str)
      c = std::towlower(c);
    map_[str]++;
  }
}
int word_frequency::frequency(const std::wstring& s)
{
  const auto it = map_.find(s);
  return it != map_.end() ? it->second : 0;
}
