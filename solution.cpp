#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol322;
using namespace std;

/*takeaways
  - DP
  - time complexity : O(n*amount)
  - space complexity: O(amount)
*/
int Solution::coinChange(vector<int> &coins, int amount)
{
  auto dp = vector<int>(amount + 1, INT_MAX);
  /* index is the amount, value is the min number
     of denominations
  */
  dp[0] = 0;

  /* consider one denomination at a time */
  for (auto coin : coins)
    /* add just one coin to every possible different amount */
    for (auto amt = coin; amt <= amount; amt++)
      /* other type of coins need to be able to come up with
         the previous sum (amt-coin) first
         - for example if the denomination is 5 and the sum
           we are looking at is 6
         - in other words, we are evaluating dp[6] by adding
           one '5' coin to the amount 1 (dp[1]).
         - however if dp[1] == INT_MAX means no one can
           produce the amount 1 yet or not yet.
         - so in the case we will not update dp[6]
      */
      if (dp[amt - coin] != INT_MAX)
        /* add one coin */
        dp[amt] = min(dp[amt], dp[amt - coin] + 1);

  return dp[amount] == INT_MAX ? -1 : dp[amount];
}