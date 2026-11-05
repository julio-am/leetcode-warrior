class Solution {

    int coinChange(vector<int>& coins, int target) {
        vector<int> dp;
        std::fill_n(std::back_inserter(dp), target+1, target+1);
        dp[0] = 0;
        
        for (int amount = 1; amount<=target; ++i) {
            for (auto coin : coins) {
                if (coin <= amount) {
                    dp[i] = min(dp[i], 1+dp[amount-coin]);
                }
            }
        }

        return dp[target] == target+1 ? -1 : dp[target];
    }
};
    
