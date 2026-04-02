class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap;
        int lss = 0;

        int l = 0; 
        int r = 0;

        while(r < s.size()){
            auto it = hashMap.find(s[r]);
            
            if(it != hashMap.end()){
                l = max(l, it->second+1);
            }

            lss = max(lss, r-l+1);
            hashMap[s[r]] = r;
            r++;
        }
        return lss;
    }
};
