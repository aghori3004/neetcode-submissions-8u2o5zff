class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        
        int ans = 0;
        int maxF = 0;
        vector<int> freqArray(26,0);
        
        for(int r = 0; r<s.size(); r++){
            freqArray[s[r] - 'A']++;
            maxF = max(maxF, freqArray[s[r] - 'A']);

            if(r-l+1 - maxF > k){
                freqArray[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
