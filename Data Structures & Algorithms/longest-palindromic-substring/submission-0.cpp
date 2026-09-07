class Solution {
public:
    string longestPalindrome(string s) {
       int maxi = 1;
       int start = 0;
       for(int i = 0; i < s.size(); i++){
            int l = i-1;
            int r = i+1;
            int count = 1;
            while(l>=0 && r <= s.size()-1 && s[l]==s[r]){
                l--; r++;
                count += 2;
            }
            if(count > maxi){
                maxi = count;
                start = l+1;
            }
            l = i;
            r = i+1;
            count = 0;
            while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                l--;r++;
                count += 2;
            }
            if(count > maxi){
                maxi = count;
                start = l+1;
            }
        }
        return s.substr(start, maxi); 
    }
};
