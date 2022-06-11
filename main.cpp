#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol322;

/* Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/
tuple<vector<int>, int, int>
testFixture1()
{
  auto input = vector<int>{1, 2, 5};
  return make_tuple(input, 11, 3);
}

/* Example 2:
Input: coins = [2], amount = 3
Output: -1
*/
tuple<vector<int>, int, int>
testFixture2()
{
  auto input = vector<int>{2};
  return make_tuple(input, 3, -1);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << get<2>(f) << endl;
  Solution sol;
  cout << sol.coinChange(get<0>(f), get<1>(f)) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 1 - exepct to see " << get<2>(f) << endl;
  Solution sol;
  cout << sol.coinChange(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}