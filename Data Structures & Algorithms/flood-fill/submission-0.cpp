class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        deque<pair<int,int>> dq;
        dq.push_back({sr,sc});
        int curr_color = image[sr][sc];
        image[sr][sc] = color;
        
        while(!dq.empty()){
            int size = dq.size();
            while(size--){
                pair<int, int> curr = dq.front();
                int i = curr.first;
                int j = curr.second;
                dq.pop_front();
                if(i+1<image.size() && curr_color == image[i+1][j]){
                    image[i+1][j] = color;
                    dq.push_back({i+1, j});
                }
                if(i-1>=0 && curr_color == image[i-1][j]){
                    image[i-1][j] = color;
                    dq.push_back({i-1, j});
                }
                if(j+1<image[i].size() && curr_color == image[i][j+1]){
                    image[i][j+1] = color;
                    dq.push_back({i, j+1});
                }
                if(j-1>=0 && curr_color == image[i][j-1]){
                    image[i][j-1] = color;
                    dq.push_back({i, j-1});
                }

            }
        }

        return image;
    }
};