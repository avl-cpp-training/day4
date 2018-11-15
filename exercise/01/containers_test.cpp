#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "containers.h"
#include <sstream>
#include <algorithm> // is_sorted

TEST_CLASS(test_standard_containers_usage)
{
public:
	TEST_METHOD(vector_remove_element)
	{
		std::vector<int> v { 1, 2, 3, 4, 5 };
		remove_element(v, 2);
		Assert::AreEqual(4u, v.size());
		Assert::AreEqual(2, v[1]);
		Assert::AreEqual(4, v[2]);
	}
	TEST_METHOD(vector_input_element)
	{
		std::vector<std::wstring> v { L"a", L"b", L"d" };
		input_element(v, 2, L"c");
		Assert::AreEqual(4u, v.size());
		Assert::AreEqual(L"c", v[2].c_str());
		Assert::AreEqual(L"d", v[3].c_str());
	}

	TEST_METHOD(list_nth_element_test)
	{
		std::list<int> c { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		Assert::AreEqual(4, list_nth_element(c, 4));
		Assert::AreEqual(8, list_nth_element(c, 8));
	}

	//TEST_METHOD(list_sort_descending)
	//{
	//	std::list<int> c { 7, 1, 5, 3, 4, 2 };
	//	list_sort_desc(c);
	//	Assert::AreEqual(6u, c.size());
	//	Assert::IsTrue(std::is_sorted(c.rbegin(), c.rend()));
	//}

	TEST_METHOD(unique_values_test)
	{
		Assert::AreEqual(5, unique_numbers(std::wstringstream(L"-9 -7 -5 -3 -1")));
		Assert::AreEqual(3, unique_numbers(std::wstringstream(L"1 2 3 2 3 2 1 2 3")));
		Assert::AreEqual(2, unique_numbers(std::wstringstream(L"0 1 1 0 0 1 0")));
	}

	TEST_METHOD(word_frequency_test)
	{
		std::wstringstream ss(L"Lorem ipsum dolor sit amet lorem ipsum dolor");
		word_frequency h(ss);
		Assert::AreEqual(5, h.count());
		Assert::AreEqual(2, h.frequency(L"lorem"));
		Assert::AreEqual(1, h.frequency(L"amet"));
		Assert::AreEqual(0, h.frequency(L"nope"));
		Assert::AreEqual(5, h.count());
	}
};
