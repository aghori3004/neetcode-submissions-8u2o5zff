class Solution {
public:
    void bfs (vector<vector<int>>& grid, int& c, deque<pair<int, int>>& dq){
        while(!dq.empty()){
            int size = dq.size();
            
            while(size){
               pair<int, int> now = dq.front();
               dq.pop_front();

               if(now.first + 1 < grid.size() && grid[now.first + 1][now.second] == 1){
                dq.push_back({now.first + 1, now.second});
                grid[now.first+1][now.second] = 2;
               }
               if(now.first - 1 >= 0 && grid[now.first - 1][now.second] == 1){
                dq.push_back({now.first - 1, now.second});
                grid[now.first -1][now.second] = 2;
               }
               if(now.second + 1 < grid[now.first].size() && grid[now.first][now.second+1] == 1){
                dq.push_back({now.first, now.second + 1});
                grid[now.first][now.second + 1] = 2;
               }
               if(now.second - 1 >= 0 && grid[now.first][now.second - 1] == 1){
                dq.push_back({now.first, now.second - 1});
                grid[now.first][now.second - 1] = 2;
               }
 

               size--;
            }

            c++;
        }
        return;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int c = -1;
        deque<pair<int, int>> dq;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 2){
                    dq.push_back({i, j});
                }
            }
        }
        if(dq.empty()) c = 0;
        bfs(grid, c, dq);
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 1){
                    c = -1;
                }
            }
        }
        return c;

    }
};
