class Solution {
public:
    bool dfs(int curr,  unordered_map<int, vector<int>>& preMap, unordered_set<int>& visited){
        if(visited.count(curr)) return false;
        if(preMap[curr].empty()){
            return true;
        }
        visited.insert(curr);
        for(int preCourse : preMap[curr]){
            if (!dfs(preCourse, preMap, visited)) return false;
        }
        visited.erase(curr);
        preMap[curr].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        for(vector<int> preReq : prerequisites){
            preMap[preReq[0]].push_back(preReq[1]);
        }
        unordered_set<int> visited;

        for(int c = 0; c < numCourses; c++){
            if(!dfs(c,preMap,visited)) return false;
        }
        return true;

    }
};
