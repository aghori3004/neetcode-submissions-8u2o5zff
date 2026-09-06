class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        
        for (int sum = 0; sum <= amount; sum ++){
            if (sum == 0){
                dp[sum] = 0;
            } else {
                for (int c : coins){
                    if (c <= sum && dp[sum-c] != INT_MAX){
                        dp[sum] = min(dp[sum], 1 + dp[sum - c]);
                    }
                }
            }
        }

        if(dp[amount] < INT_MAX) return dp[amount];
        else return -1;
    }
};
