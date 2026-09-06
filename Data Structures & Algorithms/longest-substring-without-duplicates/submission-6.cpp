class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0; int maxi = 0;
        int n = s.size();
        for (int right = 0; right < n; right++){
            while(charSet.count(s[right])){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};
