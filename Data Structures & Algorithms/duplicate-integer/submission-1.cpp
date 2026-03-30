class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0; i<nums.size(); i++){
            if (hashSet.find(nums[i]) != hashSet.end()) return true;
            else hashSet.insert(nums[i]);
        }
        return false;
    }
};