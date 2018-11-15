#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <chrono>

TEST_CLASS(test_standard_algorithms_usage)
{
public:
  TEST_METHOD(test_01)
  {
    std::wstringstream ss(L"14 -78 22");
    std::vector<int> v{};

    // TODO: read values from input stream into vector
    std::copy(std::istream_iterator<int, wchar_t>{ss}, std::istream_iterator<int, wchar_t>{},
              std::back_inserter(v));

    Assert::AreEqual(3u, v.size());
    Assert::AreEqual(14, v[0]);
    Assert::AreEqual(-78, v[1]);
    Assert::AreEqual(22, v[2]);
  }

  TEST_METHOD(test_02a)
  {
    std::vector<int> v(10);

    // TODO: fill vector with incremental values
    std::iota(v.begin(), v.end(), 1);

    Assert::AreEqual(10u, v.size());
    Assert::IsTrue(std::is_sorted(v.cbegin(), v.cend()));
    Assert::AreEqual(1, v[0]);
    Assert::AreEqual(10, v[9]);
  }

  TEST_METHOD(test_02b)
  {
    // generate
    std::vector<int> v(10);

    // TODO: fill vector with incremental values (by 2)
    std::generate(v.begin(), v.end(), []()
    {
      static int i{-1};
      return i += 2;
    });

    Assert::IsTrue(std::is_sorted(v.cbegin(), v.cend()));
    Assert::IsTrue(v.cend() == std::adjacent_find(v.cbegin(), v.cend(), [](int a, int b) { return b - a != 2; }));
    Assert::AreEqual(1, v[0]);
    Assert::AreEqual(19, v[9]);
  }

  TEST_METHOD(test_03a)
  {
    std::vector<int> v = {1, 5, 10};

    // TODO: change all values in a vector
    std::transform(v.begin(), v.end(), v.begin(), [](auto& elem) { return std::pow(elem, 3); });

    Assert::AreEqual(3u, v.size());
    Assert::AreEqual(1, v[0]);
    Assert::AreEqual(125, v[1]);
    Assert::AreEqual(1000, v[2]);
  }

  //TEST_METHOD(test_03b)
  //{
  //  int x[] = {3, 5, 10};
  //  std::vector<int> y = {4, 12, 10};
  //  std::vector<double> d;

  //  // TODO: calculate distances from origin (from x and y collections) to new vector
  //  auto dist = [](int a, int b) { return std::sqrt(std::pow(a, 2) + std::pow(b, 2)); };
  //  std::transform();

  //  Assert::AreEqual(3u, d.size());
  //  Assert::AreEqual(5., d[0]);
  //  Assert::AreEqual(13., d[1]);
  //  Assert::AreEqual(sqrt(200), d[2]);
  //}

  TEST_METHOD(test_04a)
  {
    std::wstringstream ss(L"1.5 2.5 3.5");

    // TODO: sum of all values in input stream
    auto res = std::accumulate(std::istream_iterator<double, wchar_t>{ss}, std::istream_iterator<double, wchar_t>{},
                               0.);
    Assert::AreEqual(7.5, res);
  }

  TEST_METHOD(test_04b)
  {
    std::vector<std::wstring> v{L"A", L"V", L"L", L"!"};
    // TODO: concatenated string with additional prefix 
    auto res = std::accumulate(v.cbegin(), v.cend(), std::wstring{L"GO "});
    Assert::AreEqual(L"GO AVL!", res.c_str());
  }

  TEST_METHOD(test_04c)
  {
    struct person
    {
      std::wstring name;
      int age;
    };
    std::vector<person> v{{L"Pero", 33}, {L"Iva", 25}};
    // TODO: sum of all ages
    auto total_age = std::accumulate(v.cbegin(), v.cend(), 0, [](int acc, auto const& p) { return acc + p.age; });

    Assert::AreEqual(58, total_age);
  }

  TEST_METHOD(test_05a)
  {
    std::vector<int> v{-5, 8, 11, 0, -9, 77, -4};
    auto number_of_negative = std::count_if(v.cbegin(), v.cend(), [](int elem) { return elem < 0; });
    Assert::AreEqual(3, number_of_negative);
  }

  TEST_METHOD(test_05b)
  {
    std::vector<double> v{1.5, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99};
    //condition not defined
    auto number_of_invalid = std::count_if(v.cbegin(), v.cend(), [](double elem) { return elem >= 100.; });
    Assert::AreEqual(3, number_of_invalid);
  }

  TEST_METHOD(test_05c)
  {
    struct point
    {
      int x, y;
    };
    std::vector<point> v{{1, 1}, {-5, 3}, {2, 2}, {-7, -6}, {9, -4}};
    auto number_in_first_quadrant = std::count_if(v.cbegin(), v.cend(), [](auto const& p)
    {
      return p.x >= 0 && p.y >= 0;
    });
    Assert::AreEqual(2, number_in_first_quadrant);
  }

  
    TEST_METHOD(test_06)
    {
      std::vector<int> v{33, 16, 24, 41, 25, 19, 9};
      auto first_prime = std::find(v.cbegin(), v.cend(), );
        Assert::AreEqual(41, first_prime);
    }
  //
  //  TEST_METHOD(test_07a)
  //  {
  //    std::vector<double> v{1e10, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99};
  //    // TODO: change every invalid value (1e10) with -1 
  //    Assert::AreEqual(-1., v[0]);
  //    Assert::AreEqual(-1., v[4]);
  //    Assert::AreEqual(-1., v[6]);
  //  }
  //
  //  TEST_METHOD(test_07b)
  //  {
  //    std::wstring s(L"ponedjeljak");
  //    // TODO: change every vowel with x 
  //    Assert::AreEqual(L"pxnxdjxljxk", s.c_str());
  //  }
  //
  //  TEST_METHOD(test_08a)
  //  {
  //    std::vector<double> v{1e10, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99};
  //    // TODO: delete all invalid values (1e10)
  //    Assert::AreEqual(5u, v.size());
  //    Assert::AreEqual(8., v[0]);
  //    Assert::AreEqual(99., v[4]);
  //  }
  //
  //  TEST_METHOD(test_08b)
  //  {
  //    std::wstring s(L"ponedjeljak");
  //    // TODO: delete all vowels 
  //    Assert::AreEqual(L"pndjljk", s.c_str());
  //  }
  //
  //  TEST_METHOD(test_09)
  //  {
  //    struct exam
  //    {
  //      std::wstring name;
  //      int points, grade;
  //    };
  //    std::vector<exam> v{{L"Pero", 55, 2}, {L"Iva", 93, 5}, {L"Marko", 89, 5}};
  //    // TODO: sort vector by grade, then by points
  //    Assert::AreEqual(L"Iva", v[0].name.c_str());
  //    Assert::AreEqual(L"Marko", v[1].name.c_str());
  //    Assert::AreEqual(L"Pero", v[2].name.c_str());
  //  }
  //
  //  TEST_METHOD(test_10a)
  //  {
  //    // nth_element
  //    std::vector<double> v(2e7);
  //    // half of the values less than 1000
  //    std::generate(v.begin(), v.begin() + v.size() / 2, []() { return rand() % 1000; });
  //    // other half of the values greater than 1000
  //    std::generate(v.begin() + v.size() / 2, v.end(), []() { return 1001 + rand() % 1000; });
  //    v.push_back(1000); // to be median
  //    std::random_shuffle(v.begin(), v.end());
  //
  //    using namespace std::chrono;
  //    auto t1 = steady_clock::now();
  //    // TODO: put median value in the middle of vector. fast.
  //    auto t2 = steady_clock::now();
  //    auto dur = duration_cast<milliseconds>(t2 - t1);
  //    Assert::AreEqual(1000., v[v.size() / 2]); // median value
  //    Assert::IsTrue(dur.count() < 1000, std::to_wstring(dur.count()).c_str()); // faster than 1 second
  //  }
  //
  //  TEST_METHOD(test_10b)
  //  {
  //    struct employee
  //    {
  //      std::wstring name;
  //      int salary;
  //    };
  //    std::vector<employee> v{{L"Iva", 2000}, {L"Pero", 1000}, {L"Marko", 10000}};
  //    // TODO: put employee with median salary in the middle of vector
  //    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end(), [](const employee& a, const employee& b)
  //    {
  //      return a.salary < b.salary;
  //    });
  //    Assert::AreEqual(L"Iva", v[v.size() / 2].name.c_str()); // median_salary
  //  }
  //
  //  TEST_METHOD(test_12)
  //  {
  //    std::vector<double> v{11, 0.5, -97.23, -23.11, 48.78, 22.96, -77};
  //    auto smallest_value = // TODO: 
  //      Assert::AreEqual(-97.23, smallest_value);
  //    auto largest_value = // TODO: 
  //      Assert::AreEqual(48.78, largest_value);
  //  }
  //
  //  TEST_METHOD(test_13)
  //  {
  //    std::vector<int> atp_points{8445, 7480, 6220, 5300, 5285};
  //    // the most interesting match is the one with the smallest difference
  //    auto smallest_difference = // TODO: 
  //      Assert::AreEqual(15, smallest_difference);
  //  }
};
