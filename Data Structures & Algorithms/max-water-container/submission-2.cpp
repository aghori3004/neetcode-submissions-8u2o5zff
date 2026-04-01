class Solution {
public:
    int maxArea(vector<int>& heights) {
        int beg = 0;
        int end = heights.size()-1;

        int area = (end - beg) * min(heights[beg], heights[end]);
        while(beg < end){
            if (heights[beg] <= heights[end]) beg++;
            else end --;
            
            int nArea = (end - beg) * min(heights[beg], heights[end]);
            if(nArea > area) area = nArea;
        }

        return area;
    }
};
