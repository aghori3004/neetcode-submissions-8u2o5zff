class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end());
       vector<vector<int>> ans;

       for(vector<int> interval : intervals){
        if(ans.empty()) ans.push_back(interval);
        if (interval[0] <= ans.back()[1]){
            ans.back()[1] = max(interval[1], ans.back()[1]);
        } else {
            ans.push_back(interval);
        }
       } 
       return ans;
    }
};
