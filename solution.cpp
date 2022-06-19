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
  - consider one type of coins at a time
  - dp[amount] = min(dp[amount],dp[amount-coin value]
  - time complexity : O(n*amount)
  - space complexity: O(amount)
*/
int Solution::coinChange(vector<int> &coins, int amount)
{
  /* very important to initialize everything to INT_MAX
     - if we look at the coin with a value of 5 first,
       we won't be about to come up with the amount
       1..4, so we should not update dp[1]...dp[4]
     - in this case, other coins would know no one
       has touched them yet as their value remain
       INT_MAX

  */
  /* index is the amount, value is the min number
    of denominations
 */
  auto dp = vector<int>(amount + 1, INT_MAX);

  /* base case */
  dp[0] = 0;

  /* consider one denomination at a time */
  for (auto value : coins)
    /* add just one coin to every possible different amount */
    for (auto amt = value; amt <= amount; amt++)
      /* other type of coins need to be able to come up with
         the previous sum (amt-value) first
         - for example if the denomination is 5 and the sum
           we are looking at is 6
         - in other words, we are evaluating dp[6] by adding
           one '5' coin to the amount 1 (dp[1]).
         - however if dp[1] == INT_MAX means no one can
           produce the amount 1 yet or not yet.
         - so in the case we will not update dp[6]
      */
      if (dp[amt - value] != INT_MAX)
        /* add one coin
           - there might be  different ways to get to amt
           - amount 5 = 5, 1+1+1+1+1,...
           - so we need to keep the one uses min number of coins
        */
        dp[amt] = min(dp[amt], dp[amt - value] + 1);

  return dp[amount] == INT_MAX ? -1 : dp[amount];
}