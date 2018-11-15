#include <vector>
#include <list>
#include "containers.h"
#include <set>
#include <map>
#include <locale>
#include <algorithm>

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
  return c.sort(std::greater<int>());
}

int unique_numbers(std::wistream& is)
{
  std::set<int> s;
  int v;
  while (is >> v)
  {
    s.insert(v);
  }
  return s.size();

}

word_frequency::word_frequency(std::wistream& is)
{
  std::wstring word;
  std::locale loc("");
  while (is >> word)
  {
    std::transform(word.begin(), word.end(), word.begin(), ::towlower);
    ++_m[word];
    //if (_m.find(word) == _m.end()) {
    //  // not found
    //  _m[word] = 1;
    //}
    //else {
    //  ++_m[word];
    //}
  }
};

int word_frequency::frequency(const std::wstring& s)
{
  std::map<std::wstring, int>::const_iterator i = _m.find(s);

  if (i == _m.end()) {
    return 0;
  }
  else
  {
   return _m[s];
  }
}
int word_frequency::count()
{
  return _m.size();
}