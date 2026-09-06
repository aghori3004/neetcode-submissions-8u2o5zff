class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        vector<int> ex(n);

        for(int i = 0; i < n; i++){
            if (i == 0){
                dp[i] = nums[i];
                ex[i] = 0;
            }
            else if (i == 1){
                dp[i] = max(nums[i], nums[i-1]);
                ex[i] = nums[i];
            }
            else{
                if (i != n-1){
                    dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
                    ex[i] = max(ex[i-1], nums[i] + ex[i-2]);
                } else {
                    dp[i] = max(dp[i-1], nums[i] + ex[i-2]);
                }
            }
        }

        return dp[n-1];
    }
};
