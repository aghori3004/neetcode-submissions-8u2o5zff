class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;

        for(int i = 0; i<strs.size(); i++){
            vector<int> freqVec(26,0);
            for(int j=0; j<strs[i].size(); j++){
                freqVec[strs[i][j] - 'a'] += 1;
            }
            string s = "";
            for(int j = 0; j < 26; j++){
                s = s + to_string(freqVec[j]) + " ";
            }

            hashMap[s].push_back(strs[i]);
        }
        
        for(auto& it : hashMap){
            ans.push_back(it.second);
        }

        return ans;

    }
};
