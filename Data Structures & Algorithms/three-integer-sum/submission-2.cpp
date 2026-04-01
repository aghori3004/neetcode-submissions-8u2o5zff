class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i< nums.size() && nums[i] <= 0; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            int t = -1*nums[i];
            int beg = i+1;
            int end = nums.size()-1;

            while(beg < end){
                if ((nums[beg]+nums[end]) > t) end--;
                else if ((nums[beg] + nums[end]) < t) beg++;
                else{
                    vector<int> elem = {nums[i], nums[beg], nums[end]};
                    ans.push_back(elem);
                    beg++;
                    end--;
                    while(beg < end && nums[beg] == nums[beg-1]){
                        beg++;
                    }
                }
            }
        }

        return ans;
    }
};
