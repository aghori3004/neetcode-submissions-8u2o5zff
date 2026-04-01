class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int beg = 0;
        int end = numbers.size()-1;
        
        while(beg < end){
            if((numbers[beg]+numbers[end]) > target) end--;
            else if ((numbers[beg] + numbers[end]) < target) beg++;
            else{
                vector<int> ans = {beg+1,end+1};
                return ans;
            }
        }
    }
};
