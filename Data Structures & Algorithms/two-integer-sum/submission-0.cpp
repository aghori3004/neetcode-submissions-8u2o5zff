class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            
            int toFind = target - nums[i];
            
            auto it = hashMap.find(toFind);
            if(it != hashMap.end()){
                ans.push_back(i);
                ans.push_back(it->second);
                sort(ans.begin(), ans.end());
                return ans;
            }

            else{
                hashMap.insert({nums[i], i});
            } 
        }
    }
};
