#include "containers.h"
#include <set>

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

int unique_numbers(std::wistream& stream)
{
  std::set<int> UniqueNumbers;
  int NewNumber;

  while (stream >> NewNumber)
  {
    UniqueNumbers.insert(NewNumber);
  }

  return UniqueNumbers.size();
}


////////////////////////////////////////////////////////////////////////////
word_frequency::word_frequency(std::wistream& stream)
{
  std::wstring InputString;

  while (stream >> InputString)
  {
    CastToLower(InputString);

    if (m_Words.find(InputString) != m_Words.end())
    {
       m_Words[InputString]++;
    }
    else
    {
      m_Words[InputString] = 1;
    }
  }
}


int word_frequency::count()
{
  return m_Words.size();
}


int word_frequency::frequency(const std::wstring& word)
{
  if (m_Words.find(word) != m_Words.end())
  {
    return m_Words[word];
  }

  return 0;
}


void CastToLower(std::wstring& Word)
{
  for (wchar_t& Char : Word)
  {
    Char = std::towlower(Char);
  }
}
