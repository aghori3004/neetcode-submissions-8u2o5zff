class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> charStack;
        for(char c : s){
            if(!charStack.empty() && charStack.back().first == c){
                charStack.back().second++;
                if (charStack.back().second == k) charStack.pop_back();  
            } else {
                charStack.push_back({c, 1});
            }
        }
        string ans = {};
        for(pair<char, int> chars : charStack){
            for(int i = 0; i<chars.second; i++){
                ans = ans + chars.first;
            }
        }
        return ans;
    }
};