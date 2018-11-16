#include "containers.h"
#include "set"

void remove_element(std::vector<int>& v, int index)
{
  v.erase(v.begin() + index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring & value)
{
  v.insert(v.begin() + index, value);
}

int list_nth_element(const std::list<int>& c, int index)
{
  auto it = c.begin();
  std::advance(it, index);
  return *it;
}

void list_sort_desc(std::list<int>& c)
{
  c.sort(std::greater<>());
}

int unique_numbers(std::wistream& stream)
{
  auto set = std::set<int>();
  auto curr = 0;
  while (stream >> curr)
    set.insert(curr);

  return set.size();
}

word_frequency::word_frequency(std::wistream& stream)
{
  auto word = std::wstring{};
  while (stream >> word)
    map[word]++;
}

int word_frequency::frequency(const std::wstring& s)
{
  auto found = map.find(s);
  if (found == map.end())
    return 0;
  return found->second;
}

int word_frequency::count()
{
  return map.size();
}
