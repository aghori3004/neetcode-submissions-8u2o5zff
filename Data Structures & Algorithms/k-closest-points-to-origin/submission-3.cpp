class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        
        for(int i = 0; i < points.size(); i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxPQ.push({dist, i});
            if(maxPQ.size() > k) maxPQ.pop();
        }
        vector<vector<int>> ans;
        while(!maxPQ.empty()){
            ans.push_back(points[maxPQ.top().second]);
            maxPQ.pop();
        }
        return ans;
    }
};
