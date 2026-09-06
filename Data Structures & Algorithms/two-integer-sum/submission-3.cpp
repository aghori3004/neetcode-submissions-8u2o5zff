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
                return {hashMap.at(diff), i};
            }
        }
        return {};
    }
};
