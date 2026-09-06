class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        
        for(int i = 0; i< nums.size(); i++){
            if (i == 0) dp[i] = nums[i];
            else if (i == 1) dp[i] = max(nums[i], nums[i-1]);
            else{
                dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
            }
        }
        return dp[dp.size()-1];
    }
};
