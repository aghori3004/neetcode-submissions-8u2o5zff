class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            auto it = hashMap.find(diff);

            if (it == hashMap.end()){
                hashMap[nums[i]] = i;
            } else {
                ans.push_back(hashMap.at(diff));
                ans.push_back(i);
            }
        }
        return ans;
    }
};
