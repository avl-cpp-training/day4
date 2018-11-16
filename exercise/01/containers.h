#pragma once
#include <string>
#include <vector>
#include <list>
#include <unordered_map>

void remove_element(std::vector<int>& v, int index);
void input_element(std::vector<std::wstring>& v, int index, const std::wstring& value);

int list_nth_element(const std::list<int>& c, int index);
void list_sort_desc(std::list<int>& c);

int unique_numbers(std::wistream&);

class word_frequency
{
  struct hash 
  {
    std::size_t operator()(std::wstring const& arg) const
    {
      auto hash = std::size_t{};
      for (auto const& c : arg)
        hash ^= std::hash<wchar_t>()(towlower(c));
      return hash;
    }
  };

  struct key_equal
  {
    bool operator()(std::wstring const& lhs, std::wstring const& rhs) const
    {
      if (lhs.size() != rhs.size()) return false;
      for (auto lhs_it = lhs.cbegin(), rhs_it = rhs.cbegin(); lhs_it != lhs.cend(); ++lhs_it, ++rhs_it)
        if (towlower(*lhs_it) != towlower(*rhs_it))
          return false;
      return true;
    }
  };

public:
	word_frequency(std::wistream&);
	int frequency(const std::wstring& s);
	int count();
private:
  std::unordered_map<std::wstring, int, hash, key_equal> map;
};
