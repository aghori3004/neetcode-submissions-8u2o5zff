class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hashMap;
        for(int i = 0; i<nums.size(); i++){
            hashMap[nums[i]] += 1;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto it = hashMap.begin(); it != hashMap.end(); it++){
            bucket[it->second].push_back(it->first);
        }

        for(int i = bucket.size() - 1; i >= 0; i--){
            // Iterate through whatever elements exist at this frequency
            for(int num : bucket[i]){
                ans.push_back(num);
                // Stop exactly when we've collected 'k' elements
                if (ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
    }
};
