class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> hashSet;
       for(int i : nums) hashSet.insert(i);
       
       int lcs = 0;

       for (auto it = hashSet.begin(); it != hashSet.end(); it++){
        if (hashSet.find(*it - 1) != hashSet.end()) continue;
        else{
            int currLcs = 0;
            int curr = *it;
            while(hashSet.find(curr) != hashSet.end()){
                currLcs ++;
                curr++;
            }
            if (currLcs > lcs) lcs = currLcs;
        } 
       }
       return lcs;
        
    }
};
