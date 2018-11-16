#include "containers.h"
#include <map>
#include <set>

void remove_element(std::vector<int>& v, int index) {
  v.erase(v.cbegin() + index);
}

void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value) {
  v.insert(v.cbegin() + index, value);
}

int list_nth_element(const std::list<int>& c, int index) {
  auto it = c.cbegin();
  std::advance(it, index);
  return *it;
}

bool cmp(const int &a, const int &b) {
  return a > b;
}

void list_sort_desc(std::list<int>& c) {
  c.sort(cmp);
}

int unique_numbers(std::wistream& stream) {
  std::wstring str;
  std::set<std::wstring> unique;
  while (stream >> str)
    unique.insert(str);
  return unique.size();
}

word_frequency::word_frequency(std::wistream& stream) {
  std::wstring word;
  while (stream >> word) {
    for (auto char_it = word.begin(); char_it < word.end(); ++char_it)
      *char_it = tolower(*char_it);
    string_map_[word]++;
  }  
}

int word_frequency::frequency(const std::wstring& s) {
  auto it = string_map_.find(s);
  return it != string_map_.end()
    ? it->second
    : 0;  
}

int word_frequency::count() {
  return string_map_.size();
}
