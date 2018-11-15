#include "containers.h"
#include <unordered_set>
#include <locale>

void remove_element(std::vector<int>& v, int index)
{
  v.erase(v.cbegin() + index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value)
{
  v.insert(v.cbegin() + index, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
  auto it = c.cbegin();
  std::advance(it, index);
  return *it;
}

void list_sort_desc(std::list<int>& c)
{
  c.sort(std::greater<int>());
}

int unique_numbers(std::wistream& ins)
{
  std::unordered_set<int> set{};
  int n{};

  while (ins >> n) set.emplace(n);
  return set.size();
}

word_frequency::word_frequency(std::wistream& in)
{
  std::wstring s{};
  while (in >> s)
  {
    for (auto& chr : s) chr = ::tolower(chr);
    freq_[s] += 1;
  }
}

int word_frequency::frequency(const std::wstring& s)
{
  if (freq_.find(s) != freq_.end()) return freq_[s];
  return 0;
}

int word_frequency::count()
{
 return freq_.size();
}
