#include "containers.h"
#include <set>
#include <cwctype>

std::wstring to_lower(std::wstring const& str)
{
  // std::transform unfortunatly not allowed
  std::wstring res;
  res.reserve(str.size());
  for (const wchar_t c : str)
  {
    res.push_back(std::iswupper(c) ? std::towlower(c) : c);
  }
  return res;
}

void remove_element(std::vector<int>& v, const int index)
{
  v.erase(v.begin() + index);
}

void input_element(std::vector<std::wstring>& v, const int index, const std::wstring& value)
{
  v.insert(v.begin() + index, value);
}

int list_nth_element(const std::list<int>& c, const int index)
{
  auto it = c.cbegin();
  std::advance(it, index);
  return *it;
}

void list_sort_desc(std::list<int>& c)
{
  // std::sort not allowed
  std::set<int> tmp_c;
  for (auto&& elem : c)
    tmp_c.insert(elem);
  c.clear();
  for(auto it = tmp_c.crbegin(); it != tmp_c.crend(); ++it)
    c.push_back(*it);
}

int unique_numbers(std::wistream& stream)
{
  int elem;
  std::set<int> tmp_s;
  while (stream >> elem)
  {
    tmp_s.insert(elem);
  }
  return tmp_s.size();
}

word_frequency::word_frequency(std::wistream& stream)
{
  std::wstring elem;
  while (stream >> elem)
  {
    elem = to_lower(elem);
    freq[elem]++;
  }
}

int word_frequency::frequency(const std::wstring& s) const
{
  const std::wstring lowercase_s = to_lower(s);
  const auto it = freq.find(lowercase_s);
  return (it != freq.end()) ? it->second : 0;
}

int word_frequency::count() const noexcept
{
  return freq.size();
}
