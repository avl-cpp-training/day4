#include "containers.h"
#include <set>
#include <iterator>
#include <algorithm>
#include <regex>
#include <string>
#include <numeric>

void remove_element(std::vector<int>& v, int index)
{
  v.erase(std::begin(v) + index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring & value)
{
  v.insert(std::begin(v) + index, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
  auto iter = std::cbegin(c);
  std::advance(iter, index);
  return *iter;
}

void list_sort_desc(std::list<int>& c)
{
  c.sort(std::greater<int>());
}

int unique_numbers(std::wistream& stream)
{
  std::set<int> s;
  for (auto iter = std::istream_iterator<int, wchar_t>(stream); iter != std::istream_iterator<int, wchar_t>(); ++iter)
    s.insert(*iter);
  return s.size();
}

word_frequency::word_frequency(std::wistream& s)
{
  for (auto iter = std::istreambuf_iterator<wchar_t>(s); iter != std::istreambuf_iterator<wchar_t>(); ++iter)
    text.push_back(*iter);
}

int word_frequency::frequency(const std::wstring & s)
{
  const std::wregex reg(std::wstring(L"(\\s+|^)") + s + L"(\\s+|$)", std::regex_constants::icase);
  return std::accumulate(std::regex_token_iterator<std::wstring::const_iterator>(std::cbegin(text), std::cend(text), reg, 0), std::regex_token_iterator<std::wstring::const_iterator>(), 0, [](auto acc, const auto&) {return ++acc; });;
}

int word_frequency::count()
{
  static const std::wregex reg(L"\\s+");
  std::set<std::wstring> wset;
  for (auto iter = std::regex_token_iterator<std::wstring::const_iterator>(std::cbegin(text), std::cend(text), reg, -1); iter != std::regex_token_iterator<std::wstring::const_iterator>(); ++iter)
  {
    std::wstring s = iter->str();
    std::wstring ls;
    for (auto c : s)
      ls.push_back(tolower(c));
    wset.insert(ls);
  }
    
  return wset.size();
}
