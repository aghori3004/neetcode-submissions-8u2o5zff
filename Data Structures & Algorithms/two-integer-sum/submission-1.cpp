class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(hashMap.find(diff) != hashMap.end()){
                ans.push_back(hashMap[diff]);
                ans.push_back(i);
                return ans;
            } else{
                hashMap[nums[i]] = i;
            }
        }
    }
};
