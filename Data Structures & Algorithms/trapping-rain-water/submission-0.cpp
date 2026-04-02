class Solution {
public:
    int trap(vector<int>& height) {
        int beg = 0; 
        int end = height.size()-1;

        int bMax = height[beg];
        int eMax = height[end];
        int trap = 0;

        while(beg<end){
            if(height[beg] < height[end]){
                bMax = max(bMax, height[beg]);
                if(bMax > height[beg]){
                    trap += bMax - height[beg];
                }
                beg++;
            }

            else{
                eMax = max(eMax, height[end]);
                if(eMax > height[end]){
                    trap += eMax - height[end]; 
                }
                end--;
            }
        }

        return trap;
    }
};
